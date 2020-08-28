const express = require("express");
const app = express();
const morgan = require("morgan");

const { sequelize, Info } = require("./models");
const personInfo = require("./models/Info");
const { sync } = require("./models/Info");

app.set("view engine", "ejs");
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(morgan("dev"));

// 새 테이블 생성 X
sequelize.sync({ force: false })
    .then(() => console.log("DB 접속 완료"))
    .catch(err => console.log(err));


app.get("/", async (req, res, next) => {
    try {
        const data = await personInfo.findAll({});
        //  console.log(data[0].id);
        return res.render("view", { data: data });
    }
    catch (err) {
        console.log(err);
    }
});
app.post("/add", async (req, res) => {
    const { name, mail, adress, phone, agree } = req.body;
    let number_agree = 1;

    if (agree === "on")
        number_agree = 1;
    else
        number_agree = 0;

    console.log(agree);

    try {
        const createDate = await personInfo.create({
            name: name,
            email: mail,
            Adress: adress,
            Phone: phone,
            Agree: number_agree
        });
        res.redirect("/");
    } catch (err) {
        console.log(err);
    }
});
app.get("/update/list/:id/", async (req, res) => {
    console.log(req.query);
    const { name, email, Phone, Adress, agree } = req.query;
    const { id } = req.params;
    try {
        const updateData = await personInfo.update({
            name: name,
            email: email,
            Adress: Adress,
            Phone: Phone,
            Agree: agree
        }, { where: { id: id } });
        res.redirect("/");
    } catch (err) {
        console.log(err);
    }
});

app.get("/delete/list/:id/", async (req, res) => {
    const {id} = req.params;
    try {
        const deleteData = await personInfo.destroy({
            where:{id:id}
        });
        res.redirect("/");
    } catch (err) {
        console.log(err);
    }
});
app.listen(8000, () => console.log("실행"));