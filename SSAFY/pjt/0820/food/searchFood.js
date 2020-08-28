const puppeteer = require("puppeteer");

const craw = async () => {
    try {
        const browser = await puppeteer.launch(
            {
                headless:true,
            }
        );
        const page = await browser.newPage();
        
        await page.goto("https://naver.com");
        
        await page.evaluate(()=>{
            document.querySelector("input#query").value = "메밀국수";
        })
        await page.keyboard.press("Enter");
        await page.waitFor(2000);
        await page.keyboard.press("Enter");
        await page.waitFor(2000);

       const href= await page.evaluate(()=>{
          data =  document.querySelector(".lst_type .lst .inner>a").href;
          return data;
        });
        console.log(href);
        await page.goto(href);
        await page.waitFor(2000);   

        await page.screenshot({
            path : "menu.jpg",
            fullPage:true
        });
         page.waitFor(1000);   

    } catch (err) {
        console.log(err);
    }
}

craw();