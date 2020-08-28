const puppeteer = require("puppeteer");
const fs = require("fs");

const crawler = async () => {

    const browser = await puppeteer.launch({ headless: true });
    // const page = await browser.newPage();
    // const page2 = await browser.newPage();
    // const page3 = await browser.newPage();
    const [page, page2, page3] = await Promise.all([
        browser.newPage(),
        browser.newPage(),
        browser.newPage()
    ]);

    await Promise.all([
        page.goto("https://naver.com"),
        page2.goto("https://daum.net", {waitUntil: 'networkidle2'}),
        page3.goto("https://google.com", {waitUntil: 'networkidle2'})]
    );
    
    await page.screenshot({ path: 'screenshot/test.jpg', fullPage:true });
    await page2.pdf({path:'pdf/test.pdf', format:'A4'});
    await page3.waitFor(6000);

    const html = await page3.content();
    fs.writeFileSync("example.html",html);

    await Promise.all([
        page.waitFor(3999),
        page2.waitFor(1234),
        page3.waitFor(123)]
    );
    console.log("정상적으로 작동함");

    await page.close();
    await page2.close();
    await page3.close();

    await browser.close();
};

crawler();