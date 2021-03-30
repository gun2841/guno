using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Numerics;

public enum stype { on, ing, cool };
public enum skill_type {  firework, weather}
public class Lv_skill : MonoBehaviour
{
    public Money mo;

    public Text during_time; // 스킬  지속시간
    public Text Level;
    public Text d_time; // 레벨업 시간 텍스트
    public Image LV_up_btn;

    public Animation skill_a;

    public float cool_time;
    public float conti_time; // 지속시간
    public int cur_level;//현재레벨
    BigInteger fix_mo = 100;

    public GameObject skill_effect_target;
    public stype tp;
    public skill_type sk_type;
    void Start()
    {
        Level.text = string.Format("Level   {0}", cur_level);
        LV_up_btn.transform.GetChild(0).GetComponent<Text>().text = fix_mo.ToString();
        d_time.text = time_to_text(conti_time);
    }
    public void skill_click()
    {
        if (tp != stype.on)
            return;

        if (sk_type == skill_type.firework)
            mo.skill_on_fire = true;
        else if (sk_type == skill_type.weather)
            mo.skill_on_weather = true;

        skill_effect_target.SetActive(true);
        StartCoroutine(skill_start());
    }
    IEnumerator skill_start()
    {
        tp = stype.ing;

        float Start_time = conti_time;
        skill_a.Play("skill_ing");

        while (Start_time > 0)
        {
            during_time.text = time_to_text(Start_time);
            Start_time -= 0.25f;
            yield return new WaitForSeconds(0.25f);
        }

        if (sk_type == skill_type.firework)
            mo.skill_on_fire = false;
        else if (sk_type == skill_type.weather)
            mo.skill_on_weather = false;


        skill_effect_target.SetActive(false);
        StartCoroutine(skill_cooltime());
    }
    IEnumerator skill_cooltime()
    {
        tp = stype.cool;

        float Start_time = cool_time;
        skill_a.Play("skill_cool");

        while (Start_time > 0)
        {
            during_time.text = time_to_text(Start_time);
            Start_time -= 0.25f;
            yield return new WaitForSeconds(0.25f);
        }


        tp = stype.on;
        skill_a.Play("skill_on");
    }
    string time_to_text(float target)
    {
        return string.Format("{0,00}:{1,00}", (int)(target / 60), (int)(target % 60));
    }

    public void skill_lv_up()
    {
        if (mo.have_money <  fix_mo)
            return;
        mo.have_money -= fix_mo;

        fix_mo *= 10;
        conti_time += 1f;
        cur_level++;

        Level.text = string.Format("Level   {0}", cur_level);
        d_time.text = time_to_text(conti_time);
        LV_up_btn.transform.GetChild(0).GetComponent<Text>().text = ChangeMoney( fix_mo.ToString());
        Money.Instance.update_text();
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
            if (haveGold.Length >= 10)
            {
                last4 = haveGold.Substring(haveGold.Length - 10);
                long intLast4 = long.Parse(last4);

                Val[index] = intLast4 % 1000000000;

                haveGold = haveGold.Remove(haveGold.Length - 9);
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
            long r = Val[index] * 1000000000 + Val[index - 1];
            return string.Format("{0:#.###}{1}", (float)r / 1000000000f, unit[index]);
        }
        return haveGold;
    }
}
