const puppeteer = require("puppeteer");
const axios = require("axios");
const fs = require("fs");

//디렉토리 읽기
fs.readdir(`images`, (err)=>{
    if(err)
    {
        console.error("폴더가 없읍니다.");
        fs.mkdirSync("images");
    }
})

const crawler = async () => {
    try {
        const browser = await puppeteer.launch(
            {
                headless: false
            }
        );

        const page = await browser.newPage();

        await page.goto("https://unsplash.com/");
        let result = [];

        while (result.length <= 10) {
            let srcs = await page.evaluate(() => {
                window.scrollTo(0, 0);
                let imgaes = [];
                const imgElement = document.querySelectorAll(".nDTlD");
                if (imgElement) {

                    //queryselAll = map, reduce , filter 적용 X

                    imgElement.forEach(el => {
                        const img = el.querySelector("img._2zEKz");

                        if (img && img.src) {
                            imgaes.push(img.src);
                        }
                        el.parentElement.removeChild(el);
                    });
                    window.scrollBy(0, 100);
                    setTimeout(() => {
                        window.scrollBy(0, 200);
                    }, 500);
                    return imgaes;
                }
            });
       result =  result.concat(srcs);
        await page.waitForSelector("figure"); // figure  이미지가 나올때까지 대기 
        }
    //    console.log(result);
        result.forEach(async(src)=>{
            const {data} = await axios.get(src.replace(/\?.*$/,' '),{
                responseType:`arraybuffer`
            });
            fs.writeFileSync(`images/${new Date().valueOf()}.jpeg`, data);
        })
    }
    catch (err) {
        console.log(err);
    }
}

crawler();