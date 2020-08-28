const parse = require("csv-parse/lib/sync");
const fs = require("fs");
const axios = require("axios");
const cheerio = require("cheerio");
const puppeteer = require("puppeteer");

const csv = fs.readFileSync(`${__dirname}/menu.csv`);
const records= parse(csv.toString());


const crwaler =  ()=>
{
    Promise.all(records.map(async([menu, link])=>{
        const browser = await puppeteer.launch({headless:true});

        const page = await browser.newPage();
        await page.goto(link);

        if(menu == "교촌반반시리즈")
        {
            await page.pdf({path:'half.pdf', format:'A2'});
        }
        else{
            await page.screenshot({path: `${menu}.jpg`, fullPage:true});
        }
        page.waitFor(1000);
        console.log(menu + "완료");
        await page.close();
        await browser.close();        
    }))   


};

crwaler();