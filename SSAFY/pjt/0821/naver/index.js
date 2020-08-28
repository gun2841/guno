const puppeteer = require("puppeteer");
const dotenv = require("dotenv");
dotenv.config();

const crawler = async () => {
    try {
        const browser = await puppeteer.launch({
            headless: false,
            args: [`--window-size=1920,1080`, `--disable-notifications`],
        });
        const page = await browser.newPage();

        await page.setViewport({
            width: 1080,
            height: 1080
        });
        await page.goto("https://daum.net");
        await page.waitFor(3000);
        await page.click(".link_login");
        await page.waitForSelector("#loginBtn");

        await page.type("#id", process.env.ID);
        await page.waitFor(8032);
        await page.type("#inputPwd", process.env.PASSWORD);
        await page.waitFor(3200);
        await page.click("#loginBtn");
        await page.waitFor(1000);

        await page.screenshot({path: "login.jpg"});
        await page.waitFor(1000);

        await page.click(".txt_pctop.link_mail"); // 메일
        await page.waitFor(1000);
        await page.click(".btn_comm.btn_my"); // 내게쓰기
        await page.waitFor(1000);
    
        await page.type("#mailSubject", "크롤링.. 테스트"); // 메일 제목
        await page.waitFor(1000);

       /*  
        await page.evaluate(()=>{
            document.querySelector("body").textContent = "테스트 중입니다.";
            $()
        });
        await page.waitFor(1000); */

        await page.click(".btn_toolbar.btn_write"); // 내게쓰기
        await page.waitFor(1000);


        await page.screenshot({path: "result.jpg", fullPage:true});
        await page.waitFor(1000);
    }
    catch (err) {
        console.log(err);
    }
}


crawler();