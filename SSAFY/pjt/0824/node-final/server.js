const express = require("express");
const app = express();
const morgan = require("morgan");

const {sequelize,User,Order} = require("./models");
const OrderList = require("./models/ORDER_LIST");


app.use(express.json());
app.use(express.urlencoded({extended:false}));
app.use(morgan("dev"));

//ture - 호출 시 테이블 새로 생성
sequelize.sync({force:true})
.then(()=> console.log("db접속성공"))
.catch(err=> console.log(err));


app.get("/", async (req,res,next)=>{
    try{
        const data = await Order.findAll({});
        return res.json({data:data});
    }
    catch(err)
    {
        console.log(err);
    }
});

app.post("/", async(req, res)=>{
    const createData = await Order.create({
        name:"BBQ",
        type : "치킨 데이터 삽입하기"
    });
    return res.json({createData:createData});
});

app.patch("/", async(req, res)=>{
    try{
        const updateData = await User.update({
            name:"윤하"
        },{where:{ name:"홍길동"}});
        //성공시 1반환 실패시 0 반환
        return res.json({updateData:updateData});
    }catch(err)
    {
        console.log(err);
    }
});
app.delete("/", async(req, res)=>{
    try{
        const deleteData = await User.destroy({
            where:{name:"윤하"}
        });
        return res.json({deleteData:deleteData});
    }catch(err)
    {
        console.log(err);
    }
});

app.get("/order", async(req,res)=>{
    try{
        const data = await OrderList.findAll({});
        //op.gt (초과) gte 이상 lt 미만 , lte 이하
        // ne 같지 않다
        // or 또는 . in 배열 요소중 하나 / notin 배열 요소가 다 다름
        return res.json({data});
    }catch(err){
        console.log(err);
    }
});
app.post("/order", async(req,res)=>{
    try{
        const createData = await OrderList.create({
            name:"BBQ",
            type : "치킨 데이터 삽입하기"
        });
        return res.json({createData});
    }catch(err){
        console.log(err);
    }
});
app.listen(8000, ()=> console.log("실행"));