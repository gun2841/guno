const express = require("express");
const app = express();
const dotenv = require("dotenv");
const { pool } = require("./DB/");
const { response } = require("express");
dotenv.config();

app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.set("view engine", "ejs");
app.use(express.static(`${__dirname}/views`));

app.get("/", async (req, res) => {
    try {
        const data = await pool.query("select * from todo");
       // console.log(data[0]);
        return res.render("index",{
            data:data[0]
        })
    } catch (err) {
        res.render("error", {
            title: "에러",
            data: "할일 목록 가져오기에 실패함"
        });
    }
});


app.post("/add", async (req, res) => {
    console.log(req.body);
    const { todo } = req.body;
    try {
        const data = await pool.query("insert into todo set ?", [{
            todo: todo, checked: "false",
        }
        ]);
        res.redirect("/"); // "/" 라우터로 다시 요청
    } catch (err) {

        res.render("error", {
            title: "에러",
            data: "할일 목록 추가에 실패함"
        });
    }
});

app.get("/update/check/:id", async (req,res)=>{
    const {id} = req.params;
    const { checked} = req.query;
    try{
        const data = await pool.query("update todo set checked = ? where id = ?",
        [
            checked , id
        ]);
        res.redirect("/");
    }catch(err){
        res.render("error", {
            title:"error",
            data:"체크목록 수정에 실패 하였습니다."
        });
    }
});

app.get("/update/todo/:id/", async (req,res)=>
{
    console.log(req.params);
    console.log(req.query);
    const {id} = req.params;
    const{todo} = req.query;
    try{
        const data = await pool.query("update todo set todo = ? where id = ?",[
            todo, id
        ]);
        res.redirect("/");
    }catch(err)
    {
        res.render("error",{
            title:"error",
            data : "할 일 목록 수정에 실패 하였습니다."
        })
    }
});
app.get("/delete/todo/:id/", async (req,res)=>{
    const {id} = req.params;
    try{
        const data = await pool.query("delete from todo where ?",[{id}]);
        res.redirect("/");
    }catch(err)
    {
        res.render("error", {
            title:"error",
            data : "삭제에 실패 하였습니다."
        })
    }
});
app.listen(8000, () => console.log("8000포트 실행"));