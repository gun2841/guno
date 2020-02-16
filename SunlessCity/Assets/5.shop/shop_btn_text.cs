using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Spine.Unity;
public class shop_btn_text : MonoBehaviour {
    public inventory ivt;
    public GameObject buy_btn;
    public GameObject gain_btn;
    public GameObject instantbtn;
    public Text time_txt;
    public Animation gain_ani;
    public SkeletonGraphic sk;
    IEnumerator startgain()
    {
        float time = 15f;

        while (time >= 0)
        {
            time_txt.text = (int)(time/60) +" : "+time%60;
            time -= 1f;
            yield return new WaitForSeconds(1.0f);
        }
        time_txt.text = "";
        instantbtn.SetActive(false);
        gain_btn.SetActive(true);
    }
    IEnumerator skeletonani_(int idx)
    {
        gain_ani.Play("gain_ani");


        SkeletonGraphic skg;
        skg = sk.GetComponent<SkeletonGraphic>();
        skg.skeletonDataAsset = Resources.Load("building/" + ivt.idb.items[idx].Spine) as SkeletonDataAsset;

    switch(ivt.idb.items[idx].width)
        {
            case 1:
                skg.rectTransform.anchoredPosition = new Vector2(-64,-210);
                break;
            case 2:
                skg.rectTransform.anchoredPosition = new Vector2(-61, -210);
                break;
            case 3:
                skg.rectTransform.anchoredPosition = new Vector2(-194, -210);
                break;
            case 4:
                skg.rectTransform.anchoredPosition = new Vector2(-128, -210);
                break;
            case 5:
                skg.rectTransform.anchoredPosition = new Vector2(-148, -210);
                break;
            default:
                break;
        }


        skg.startingLoop = true;
        skg.timeScale = 1f;
        skg.Initialize(true);
        #region
        float anitime = 0.2f;
        string basic = "b_v1_l2_";

        sk.AnimationState.SetAnimation(0, basic + 'o', true);
        yield return new WaitForSeconds(anitime);
        sk.AnimationState.SetAnimation(0, basic + 'c', true);
        yield return new WaitForSeconds(anitime);
        sk.AnimationState.SetAnimation(0, basic + 'b', true);
        yield return new WaitForSeconds(anitime);
        sk.AnimationState.SetAnimation(0, basic + 'y', true);
        yield return new WaitForSeconds(anitime);

        basic = "b_v2_l2_";
        sk.AnimationState.SetAnimation(0, basic + 'o', true);
        yield return new WaitForSeconds(anitime);
        sk.AnimationState.SetAnimation(0, basic + 'c', true);
        yield return new WaitForSeconds(anitime);
        sk.AnimationState.SetAnimation(0, basic + 'b', true);
        yield return new WaitForSeconds(anitime);
        sk.AnimationState.SetAnimation(0, basic + 'y', true);
        yield return new WaitForSeconds(anitime);

        basic = "b_v3_l2_";
        sk.AnimationState.SetAnimation(0, basic + 'o', true);
        yield return new WaitForSeconds(anitime);
        sk.AnimationState.SetAnimation(0, basic + 'c', true);
        yield return new WaitForSeconds(anitime);
        sk.AnimationState.SetAnimation(0, basic + 'b', true);
        yield return new WaitForSeconds(anitime);
        sk.AnimationState.SetAnimation(0, basic + 'y', true);
        yield return new WaitForSeconds(anitime);
        basic = "r_v3_l2_";
        sk.AnimationState.SetAnimation(1, basic + 'o', true);
        yield return new WaitForSeconds(anitime);
        sk.AnimationState.SetAnimation(1, basic + 'c', true);
        yield return new WaitForSeconds(anitime);
        sk.AnimationState.SetAnimation(1, basic + 'b', true);
        yield return new WaitForSeconds(anitime);
        sk.AnimationState.SetAnimation(1, basic + 'y', true);
        yield return new WaitForSeconds(anitime);

#endregion


        ivt.gain(idx);
        gain_ani.Play("gain_reverse");
    }
    public void gain()
    {
        int idx = Random.Range(0, 23);
        StartCoroutine("skeletonani_", idx);
        gain_btn.SetActive(false);
        buy_btn.SetActive(true);
    }
    public void enter()
    {
        buy_btn.SetActive(false); instantbtn.SetActive(true);
        StartCoroutine("startgain");
    }
    public void ad_buy()
    {
        StopCoroutine("startgain");
        buy_btn.SetActive(true); instantbtn.SetActive(false);
    }
}
