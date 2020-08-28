const express = require("express");
const multer = require("multer");
const path = require("path");
const app = express();

app.set("view engine", "ejs");
app.use(express.urlencoded({extended: false}));
app.use(express.json());

const upload = multer({
    storage: multer.diskStorage({
        // 파일업로드 위치 지정
        destination:(req,file,done)=>{
            done(null,"uploads/");
        },
        filename:(req,file,done)=>{
            console.log(file);
            const ext = path.extname(file.originalname);
            //index.html 
            // index + 날씨 123141 + .확장자
            done(null,path.basename(file.originalname,ext)+Date.now() + ext);
        }
    
    }),
    limits:{fileSize:15*1024*1024} //15메가
})

app.post("/upload", upload.single("userfile"),(req,res)=>{
    console.log(req.file);
    return res.json({data:req.file});
})
app.post("/upload-multiple-fields", 
    upload.fields([{name:"userfile1"},{name:"userfile2"}, {name:"userfile3"}]),
    (req,res)=> {
        console.log(req.files);
        return res.json({data:req.files});
    });
app.post("/upload-multiple",
upload.array("userfiles"),(req,res)=>{ 
    console.log(req.files);
    return res.json({data:req.files});
});

app.get("/", (req,res)=>{
    return res.render("index");
});

app.listen(8000, ()=> console.log("가동"));