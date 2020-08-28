const parse = require("csv-parse/lib/sync");
const fs = require("fs");

// 한번실행될때 사용하는 sync
//여러번 호출되거나 할때는 sync 사용하지 않고 기존 비동기 사용
// promise를 사용

const csv = fs.readFileSync("./csv/FL_insurance_sample.csv");
const record = parse(csv.toString());


const [one , ...other] = record;
console.log(one);

// let arr = record.fil/ter(li=>{return (li[16] === "Wood" &&  li[2] === "MIAMI DADE COUNTY")});

// console.log(arr);