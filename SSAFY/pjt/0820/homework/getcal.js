const fs = require("fs");
const axios = require("axios");
const cheerio = require("cheerio");


const craw = async () => {
        let ans = [];
        const response = await axios.get("https://www.shakeshack.com/food-and-drink/");
        if (response.status === 200) {
                const html = response.data;
                const $ = cheerio.load(html);
                //console.log(html);
                $("ul.menu-list li").each(function (i, el) {
                        let cal = $(this).find('p').find('strong').text();
                        cal = cal.split("cal");
                        let temp = cal[0].split(" ");
                        //cal = cal.split("/");
                        cal = Number(temp[temp.length-2]) ? Number(temp[temp.length-2]) : 0;
                        ans[i] = {
                                menu :$(this).find('h3').text(),
                                cal : cal
                        }
                }
                )
        }
       ans.sort(function(a,b){
               if(a.cal> b.cal){
                        return 1;
               }
               else{
                       return -1;
               }
       });
       console.log(ans);


}

craw();