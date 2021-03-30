using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Numerics;
public class Money : MonoBehaviour
{
    private static Money _instance = null;
    public static Money Instance
    {
        get
        {
            if(_instance == null)
            {
                _instance = FindObjectOfType(typeof(Money)) as Money;
                if(_instance == null)
                {
                    Debug.LogError("no active manager");
                }
            }
            return _instance;
        }
    }
    #region 기본
    //보유 하고 있는 돈
    public BigInteger have_money; // 가장중요한 포인트
    public ulong jewel;
    public ulong ticket;

    BigInteger total_auto_increase_money;        // 자동업데이트 총 증가량
    BigInteger auto_increase_money;                 // 자동업데이트 기본 증가량

    BigInteger total_click_increase_money;      //클릭업데이트 총 증가량
    BigInteger click_increase_money;               // 클릭업데이트 기본 증가량
    //
    public GameObject[] tif;//건물
    #endregion
    public Text money_txt;
    public Text jewel_txt;
    public Text ticket_txt;

    public Text shop_money_txt;
    public Text shop_jewel_txt;
    public Text shop_ticket_txt;

    BigInteger click_money_desire; // 클릭 업데이트 요구량
    BigInteger auto_moneY_desire; // 자동 업데이트 요구량
    #region 티켓
    int ticket_count;
    BigInteger ticket_price;
    #endregion
    #region 레벨디자인
    ///
    int level_click;                         // 클릭 레벨
    int level_auto;                        //  자동 레벨


    [Header("클릭")]
    public Text click_money_txt;
    public Text click_cur_level;
    public Text click_desire_;

    [Header("자동")]
    public Text auto_money_txt;
    public Text auto_cur_level;
    public Text auto_desire_;

    public bool skill_on_fire;
    public bool skill_on_weather;
    #endregion

    public void change_event_click()
    {
        if (have_money >= click_money_desire)
        {
            have_money -= click_money_desire;
            level_click++;

            click_money_desire += (click_money_desire * 15 / 10 );
            click_increase_money = click_increase_money + (click_increase_money * 13) / 10;
       
            update_ins_money();

            click_desire_.text = ChangeMoney(click_money_desire.ToString());
            click_money_txt.text = ChangeMoney(click_increase_money.ToString());
            click_cur_level.text = string.Format("Level   {0}", level_click);
        }
    }
    public void change_event_auto()
    {
        if (have_money >= auto_moneY_desire)
        {
            have_money -= auto_moneY_desire;
            level_auto++;

            auto_moneY_desire += (auto_moneY_desire * 15 / 10);
            auto_increase_money = auto_increase_money + (auto_increase_money * 14) / 10;

            update_ins_money();

            auto_desire_.text = ChangeMoney(auto_moneY_desire.ToString());
            auto_money_txt.text = ChangeMoney(auto_increase_money.ToString());
            auto_cur_level.text = string.Format("Level   {0}", level_auto);
        }
    }
    public void click_ins_update(int index)
    {
        //cins_r[index] = tif[index].transform.GetComponentInChildren<test_info>().click_ins;
        //ains_r[index] =  tif[index].transform.GetComponentInChildren<test_info>().auto_ins;
        update_ins_money();
    }
    public void update_ins_money()
    {

        total_auto_increase_money = auto_increase_money;
        total_click_increase_money = click_increase_money;
        for (int i = 0; i < tif.Length; i++)
        {
            if (tif[i].transform.childCount == 0)
                continue;
            if (tif[i].transform.childCount != 0)
            {
               // tif[i].transform.GetComponentInChildren<test_info>().update_ins();
              //  ins_money += tif[i].transform.GetComponentInChildren<test_info>().auto_ins;
                //click_ins_money += tif[i].transform.GetComponentInChildren<test_info>().click_ins;
            }
        }
        update_text();
    }
    void Start()
    {

        have_money = 1000; level_click = 1; level_auto = 1; click_increase_money = 10;
        auto_increase_money = 10; auto_moneY_desire = 100; click_money_desire = 100;

        //티켓부분
        ticket = 0;
        ticket_count = 0;
        ticket_price = 100;
        //
        click_desire_.text = ChangeMoney(click_money_desire.ToString());
        click_money_txt.text = ChangeMoney(click_increase_money.ToString());
        click_cur_level.text = string.Format("Level   {0}", level_click);

        auto_desire_.text = ChangeMoney(auto_moneY_desire.ToString());
        auto_money_txt.text = ChangeMoney(auto_increase_money.ToString());
        auto_cur_level.text = string.Format("Level   {0}", level_auto);

        money_txt.text = ChangeMoney(have_money.ToString());
        jewel_txt.text = jewel.ToString();
        ticket_txt.text = ticket.ToString();

        shop_money_txt.text = ChangeMoney(have_money.ToString());
        shop_jewel_txt.text = jewel.ToString();
        shop_ticket_txt.text = ticket.ToString();


        update_ins_money();
        //  StartCoroutine("update_money");
    }
    IEnumerator update_money()
    {
        while (true)
        {
            have_money += total_auto_increase_money;
            if (skill_on_fire == true && skill_on_weather == true)
            {
                have_money += total_auto_increase_money * 3;
            }
            else if (skill_on_fire == true || skill_on_weather == true)
            {
                have_money += total_auto_increase_money;
            }
                update_text();
            yield return new WaitForSeconds(1.0f);
        }
    }
    public void tap()
    {
        if (skill_on_fire == true  && skill_on_weather == true)
        {
            have_money += total_click_increase_money*3;
        } else if(skill_on_fire ==true || skill_on_weather == true)
        {
            have_money += total_click_increase_money;
        }
        have_money += total_click_increase_money;

        update_text();
    }
  public  void update_text()
    {
        money_txt.text = ChangeMoney(have_money.ToString());
        shop_money_txt.text = ChangeMoney(have_money.ToString());
    }
    public void gain_money(string gain)
    {
        have_money += BigInteger.Parse(gain) ;
    }

    public void ticket_gain()
    {
        if (have_money > ticket_price)
        {
            have_money -= ticket_price;
            ticket += 60;
        }
    }

    void OnApplicationQuit()
    {
        PlayerPrefs.SetString("star_point", have_money.ToString());
        PlayerPrefs.SetInt("click_level", level_click);
        PlayerPrefs.SetInt("auto_level", level_auto);
        PlayerPrefs.SetString("click_ups", click_increase_money.ToString());
        PlayerPrefs.SetString("auto_ups", auto_increase_money.ToString());
        PlayerPrefs.SetString("standard_click", click_money_desire.ToString());
        PlayerPrefs.SetString("standard_auto", auto_moneY_desire.ToString());
      //  PlayerPrefs.Save();
    }
    string ChangeMoney(string haveGold)
    {
        string[] unit = new string[] {"","A","B","C", "E", "F", "G", "H", "I", "J", "K", "L"
        ,"M","N","O","P","Q","R","S","T", "U","V","W","X","Y","Z"};
        long[] Val = new long[26];
        int index = 0;
        while (true)
        {
            string last4 = "";
            if (haveGold.Length >= 6)
            {
                last4 = haveGold.Substring(haveGold.Length - 6);
                long intLast4 = long.Parse(last4);

                Val[index] = intLast4 % 100000;

                haveGold = haveGold.Remove(haveGold.Length - 5);
            }
            else
            {
                Val[index] = long.Parse(haveGold);
                break;
            }
            index++;
        }
        if (index > 0)
        {
            long r = Val[index] * 100000 + Val[index - 1];
            return string.Format("{0:#.#}{1}", (float)r / 100000, unit[index]);
        }
        return haveGold;
    } //돈 단위 변화  숫자 -> 문자
    //----------------------------------
}
