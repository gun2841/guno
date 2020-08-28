const express =require("express");
const app = express();
const http = require("http").Server(app);
const io = require("socket.io")(http);

app.set("view engine", "ejs");


app.use(express.static(`${__dirname}/views`));

app.get("/", (req,res)=>{
    res.render("chat");
});

io.on("connection",(socket)=>{
    console.log("연결됨");
    socket.on("chat message",msg=>{
        console.log(msg);
        io.emit("chat message", msg);
    })
});

const chatRomm =io.of("/chat-room");
chatRomm.on('connection', (scoket)=>{
 console.log("연결");
 scoket.on("chat message",msg=>{
     console.log(msg);
     chatRomm.emit("chat message", msg);
 })   
})

http.listen(9000,()=>console.log("성공"));

