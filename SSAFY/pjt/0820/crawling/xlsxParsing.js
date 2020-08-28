const  xlsx = require("xlsx");
const book = xlsx.readFile("./xlsx/data-movie.xlsx");

const b = book.Sheets.영화목록;

const records = xlsx.utils.sheet_to_json(b);
console.log(records);