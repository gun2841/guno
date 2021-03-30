using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Spine.Unity;
public class view_mgr : MonoBehaviour
{
    public SkeletonGraphic skg;
    public Sprite[] sky;
    public Image Object_sky;
    public string cur_ani_name;

    public SkeletonGraphic background_skg;


    public void change_kor()
    {
        if (cur_ani_name == "0view_kor")
            return;

        cur_ani_name = "0view_kor";
        skg.AnimationState.SetAnimation(0, "0view_kor", true);
    }
    public void change_jpn()
    {
        if (cur_ani_name == "0view_jpn")
            return;

        cur_ani_name = "0view_jpn";
        skg.AnimationState.SetAnimation(0, "0view_jpn", true);
    }
    public void change_us()
    {
        if (cur_ani_name == "0view_us")
            return;

        cur_ani_name = "0view_us";
        skg.AnimationState.SetAnimation(0, "0view_us", true);
    }

    public void sky_change(int idx)
    {

        string background_name = "bg_mt_";
        Object_sky.sprite = sky[idx];
        switch (idx)
        {
            case 0:
                if (buildmgr.Instance.Sky_TYPE == sky_type.blue)
                    return;
                background_name += "b";
                buildmgr.Instance.Sky_TYPE = sky_type.blue;
                break;
            case 1:
                if (buildmgr.Instance.Sky_TYPE == sky_type.red)
                    return;

                background_name += "r";
                buildmgr.Instance.Sky_TYPE = sky_type.red;
                break;
            case 2:
                if (buildmgr.Instance.Sky_TYPE == sky_type.yellow)
                    return;

                background_name += "y";
                buildmgr.Instance.Sky_TYPE = sky_type.yellow;
                break;
            case 3:
                if (buildmgr.Instance.Sky_TYPE == sky_type.blue)
                    return;
                background_name += "b";
                buildmgr.Instance.Sky_TYPE = sky_type.blue;
                break;
        }
        buildmgr.Instance.sky_change();
        background_skg.AnimationState.SetAnimation(0, background_name, true);
    }
}