const express = require("express");
const app = express();
const morgan = require("morgan");
const PORT = 8000;
const { sequelize, User, Post } = require("./models");
const { comparePassword, hashPassword } = require("./utils/bcrypt");
const multer = require("multer");
const path = require("path");
const { createHmac } = require("crypto");
const fs = require("fs").promises;
const cors = require("cors");

app.use(morgan("dev"));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cors({
    origin:true,
    credentials:true
}))


sequelize.sync({ force: false })
    .then(() => console.log("db 접속 성공"))
    .catch(err => console.log(err));


const upload = multer({
    storage: multer.diskStorage({
        destination: (req, file, done) => {
            done(null, "uploads/");
        },
        filename: (req, file, done) => {
            const ext = path.extname(file.originalname);
            // abcd.txt
            // abcd+&& +시간.txt
            const fileName = path.basename(file.originalname, ext)+"&&"+Date.now()+ext; // 확장자 제외 
            done(null, fileName);
            req.fileDir = fileName;

        }
    }),
    limits: { fileSize: 5 * 1024 * 1024 },

});


app.get("/api/user", (req, res) => {

});


app.post("/api/user/exist", async(req, res) => {
    try{
        console.log(req.body);
        const {email} = req.body;
        const userList = await User.findOne({
            attributes:["id","email"],
            where:{
                email:email
            }
        });
        if(userList)
        {
            return res.json({exist:true});
        }else{
            return res.json({exist:false});
        }
    }catch(err){
        console.log(err);
    }
});

app.post("/api/user", async (req, res) => {
    try {
        console.log(req.body);
        const { email, password, name } = req.body;
        // 0 null -> false
        if (email && password && name) {
            //db에 저장
            const hashedPassword = await hashPassword(password);
            console.log(hashedPassword);
            const data = await User.create({
                email: email,
                password: hashedPassword,
                name: name
            });
            console.log(data);
            return res.json({ signup: true })
        } else {
            throw new Error();
        }
    }
    catch (err) {
        console.log(err);
        return res.json({ signup: false })
    }
});

app.post("/api/login", async (req, res) => {
    try {
        console.log(req.body);
        const { email, password } = req.body;
        // 암호화된 비밀번호를 가져와서 비교
        const userData = await User.findOne({
            attributes: ["id", "password"],
            where: {
                email: email
            }
        });
        const hashedPassword = userData.dataValues.password;
        console.log(userData);
        const compareResult = await comparePassword(password, hashedPassword);
        console.log(compareResult);

        if (compareResult) {
            return res.json({ login: true, id: userData.dataValues.id });
        }
        else {
            throw new Error();
        }
    } catch (err) {
        return res.json({ login: false });
    }
});

app.get("/api/post", async (req, res) => {
    try {
        const postList = await Post.findAll({});
        console.log(postList);
        return res.json({ postList });
    }
    catch (err) {
        console.log(err);
    }
});

//게시글작성
app.post("/api/post", upload.single("file"), async (req, res) => {

    try {
        console.log(req.body);
        const { title, content, userId } = req.body;
        console.log(req.fileDir);
        const post = await Post.create({
            title: title,
            content: content,
            file: req.fileDir,
            user_id: userId
        });
        console.log(post);
        return res.json({ upload: true });
    }
    catch (err) {
        console.log(err);
        return res.json({ upload: false });
    }
});

app.listen(PORT, () => console.log(`this server listening on ${PORT}`));