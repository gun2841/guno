const parse = require("csv-parse/lib/sync");
const fs = require("fs");
const axios = require("axios");
const cheerio = require("cheerio");

const csv = fs.readFileSync(`${__dirname}/csv/data-movie.csv`);
const records = parse(csv.toString());



const crawler=()=>
{
    Promise.all(records.map(async ([title,link])=>{
        //document.querySelectorAll(".score.score_left .star_score");
        const response = await axios.get(link);
        if(response.status === 200)
        {
            const html = response.data;
            const $ = cheerio.load(html);
            const text = $(".score.score_left .star_score").text().trim();
            const age = $(".info_spec dd:nth-of-type(4) a").text();
            console.log(title,text, age);
        }
    }))
};




crawler();