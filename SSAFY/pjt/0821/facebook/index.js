const puppeteer = require("puppeteer");
const dotenv = require("dotenv");
dotenv.config();

const crawler = async () => {
    try {
        const browser = await puppeteer.launch({
            headless: false,
            args: [`--window-size=1920,1080`, `--disable-notifications`],
            userDataDir: 'C:\Users\guno\AppData\Local\Google\Chrome\User Data'
        });
        const page = await browser.newPage();

        await page.setViewport({
            width: 1080,
            height: 1080
        });

        await page.setUserAgent("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.125 Safari/537.36");
        await page.goto("https://facebook.com");

        const flag = await page.evaluate(() => {

            const loginData = document.querySelector("._1vp5");
            if (loginData) return true;

            return false;
        });

        if (!flag) {
            await page.waitFor(3000);
            await page.type("#email", process.env.EMAIL);
            await page.waitFor(3032);
            await page.type("#pass", process.env.PASSWORD);
            await page.waitFor(3200);
            await page.click("button[type=submit]");
        }
        await page.waitForSelector("[id^=hyperfeed_story]");
        //피드가져오기
        // document.querySelectorAll("[id^=hyperfeed_story]") 

        let result = [];
        while (result.length < 10) {
            const newPost = await page.evaluate(() => {
                const firstFeed = document.querySelector("[id^=hyperfeed_story]");
                const postId = firstFeed.id.split("_").slice(-1)[0];
                const content = firstFeed.querySelector(".userContent") && firstFeed.querySelector(".userContent").textContent;
                const name = firstFeed.querySelector(".fwb.fcg a") && firstFeed.querySelector(".fwb.fcg a").textContent;
                const img = firstFeed.querySelector(".mtm img") && firstFeed.querySelector(".mtm img").src;
                return {
                    postId,
                    name,
                    img,
                    content
                }
            });

            console.log(newPost);

            await page.waitFor(1000);
            await page.evaluate(() => {
                const firstFeed = document.querySelector("[id^=hyperfeed_story]");
                const liked = firstFeed.querySelector("._3_16");
                const likeButton = firstFeed.querySelector("._6a-y");
                if (!liked) {
                    likeButton.click();
                }
                firstFeed.parentNode.removeChild(firstFeed);
            });

            await page.waitFor(1000);
            result.push(newPost);
        }
        console.log(result);
    }
    catch (err) {
        console.log(err);
    }
}


crawler();