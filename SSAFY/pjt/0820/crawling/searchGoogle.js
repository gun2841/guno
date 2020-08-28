const puppeteer = require("puppeteer");

const crawler = async () => {
    try {
        const browser = await puppeteer.launch(
            {
                headless: false,
                args:["--window-size=1920,1080"]
            });
        const page = await browser.newPage();
        page.setViewport({
            width:1920,
            height:1080
        })
        await page.goto("https://www.google.com");
        await page.evaluate(()=>{
            console.log("hi");
            document.querySelector("input.gsfi").value = "윤하";
        })
        await page.keyboard.press("Enter");
        await page.waitFor(2000);
        await page.evaluate(()=>{
            document.querySelector("#rso .rc .r>a").click();
        })

    } catch (err) {
        console.log(err);
    }
}

crawler();