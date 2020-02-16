using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Spine.Unity;
using UnityEngine.UI;
using UnityEngine.EventSystems;
public enum type { basic, drag };
public enum sky_type { blue,red,yellow};
public class buildmgr : MonoBehaviour
{
    private static buildmgr _instance = null;
    public static buildmgr Instance
    {
        get
        {
            if (_instance == null)
            {
                _instance = FindObjectOfType(typeof(buildmgr)) as buildmgr;
                if (_instance == null)
                {
                    Debug.LogError("no active manager");
                }
            }
            return _instance;
        }
    }

    public GameObject line1;
    public GameObject line2;
    public GameObject line3;
    [Header("타겟이미지")]
    public GameObject view1;
    public GameObject view2;
    public GameObject view3;

    public GameObject water_;
    [Header("건물 정보 창")]
    public GameObject bu_se_mode;
    public Text bu_over_thema;
    public Text bu_over_width;
    public Text bu_over_name;
    public Text bu_over_level;
    public Text bu_over_effect;

    public GameObject spine_img;
    public GameObject bu_spine_img;
    private SkeletonGraphic skg;


    // 현재 선택된 놈
    string target_name;
    int width;
    int index;
    int level;
    string thema;
    //
    public string aniName;
    //

    /// <summary>
    /// </summary>

    public bool[] line_1;
    public bool[] line_2;
    public bool[] line_3;
    public type tp;

    //현재 타겟 이미지
    GameObject targetObj;

    int target_check_value;
    //dasf
   public sky_type Sky_TYPE;
    void Start()
    {
        tp = type.basic;
    }

    public void land_over_on(GameObject senderObj)
    {
        if (senderObj.GetComponent<build_info>().thema == "")
            return;

        bu_se_mode.GetComponent<Animation>().Play("bu_over_land");

        index = senderObj.GetComponent<build_info>().index;
        width = senderObj.GetComponent<build_info>().width;
        target_name = senderObj.GetComponent<build_info>().name;
        thema = senderObj.GetComponent<build_info>().thema;
        target_check_value = senderObj.GetComponent<build_info>().target;

        bu_over_thema.text = thema;
        bu_over_width.text = width.ToString();
        bu_over_name.text = GameObject.Find("inventory_mgr").GetComponent<ItemDB>().items[index - 1].name; ;
        bu_over_level.text = "";

        bu_se_mode.SetActive(true);
        skg = bu_spine_img.GetComponent<SkeletonGraphic>();
        skg.skeletonDataAsset = Resources.Load("building/" + thema + "/" + target_name) as SkeletonDataAsset;
        skg.startingAnimation = aniName;
        skg.startingLoop = true;
        skg.timeScale = 1.0f;
        skg.Initialize(true);

        targetObj = senderObj;
        bu_spine_img.GetComponent<RectTransform>().anchoredPosition = new Vector2(-32 * width * skg.skeletonDataAsset.scale * 100, -214);
        //
    }
    public void build_over_on(GameObject senderObj)
    {
        if (tp != type.basic)
            return;

        bu_se_mode.GetComponent<Animation>().Play("bu_over_inven");
        bu_se_mode.SetActive(true);
        //
        width = senderObj.GetComponent<test_info>().width_;
        index = senderObj.GetComponent<test_info>().index;
        thema = senderObj.GetComponent<test_info>().thema;
        level = senderObj.GetComponent<test_info>().level;
        target_name = senderObj.GetComponent<test_info>().name_;
        //GameObject.Find("inventory_mgr").GetComponent<ItemDB>().items[index-1].name;
        bu_over_thema.text = thema;
        bu_over_width.text = width.ToString();
        bu_over_name.text = GameObject.Find("inventory_mgr").GetComponent<ItemDB>().items[index - 1].name;
        bu_over_level.text = "Lv " + level.ToString();
        //bu_over_effect;
        //
        skg = bu_spine_img.GetComponent<SkeletonGraphic>();
        skg.skeletonDataAsset = Resources.Load("building/" + thema + "/" + target_name) as SkeletonDataAsset;
        skg.startingAnimation = aniName;
        skg.startingLoop = true;
        skg.timeScale = 1.0f;
        skg.Initialize(true);

        bu_spine_img.GetComponent<RectTransform>().anchoredPosition = new Vector2(-32 * width * skg.skeletonDataAsset.scale * 100, -214);
        //
        targetObj = senderObj;
    }
    public void build_exit()
    {
        skg = null;
        targetObj = null;
        target_name = null;
        width = -1;
        index = -1;
        level = -1;
        thema = null;
        bu_se_mode.SetActive(false);
    }
    public int building_check(int Parent, int target, bool dir, Dnditem dnditem)
    {
        if (Parent == 1)
        {
            switch (dnditem.width)
            {
                case 1:
                    if (line_1[target - 1] == true)
                    {
                        line_1[target - 1] = false;
                        spine_building_(1, target - 1, dnditem);
                        line1_raycast_setactive(1, target - 1, dnditem);
                        return target - 1;
                    }
                    break;
                case 2:
                    if (dir && target < 10)
                    {
                        if (line_1[target - 1] && line_1[target])
                        {
                            line_1[target - 1] = false; line_1[target] = false;
                            spine_building_(1, target - 1, dnditem);
                            line1_raycast_setactive(2, target - 1, dnditem);
                            return target - 1;
                        }
                    }
                    else if (!dir && target > 1)
                    {
                        if (line_1[target - 1] && line_1[target - 2])
                        {
                            line_1[target - 1] = false; line_1[target - 2] = false;
                            spine_building_(1, target - 2, dnditem);
                            line1_raycast_setactive(2, target - 2, dnditem);
                            return target - 2;
                        }
                    }
                    break;
                case 3:
                    if (target < 10 && target > 1)
                    {
                        if (line_1[target - 2] && line_1[target - 1] && line_1[target])
                        {
                            line_1[target - 2] = line_1[target - 1] = line_1[target] = false;
                            spine_building_(1, target - 2, dnditem);
                            line1_raycast_setactive(3, target - 2, dnditem);
                            return target - 2;
                        }
                    }
                    break;
                case 4:
                    if (dir && target < 9 && target > 1)
                    {
                        if (line_1[target - 1] && line_1[target] && line_1[target + 1] && line_1[target - 2])
                        {
                            line_1[target - 2] = line_1[target - 1] = line_1[target] = line_1[target + 1] = false;
                            spine_building_(1, target - 2, dnditem);
                            line1_raycast_setactive(4, target - 2, dnditem);
                            return target - 2;
                        }
                    }
                    if (!dir && target < 10 && target > 2)
                    {
                        if (line_1[target - 3] && line_1[target - 2] && line_1[target] && line_1[target - 1])
                        {
                            line_1[target - 3] = line_1[target - 2] = line_1[target] = line_1[target - 1] = false;
                            spine_building_(1, target - 3, dnditem);
                            line1_raycast_setactive(4, target - 3, dnditem);
                            return target - 3;
                        }
                    }
                    break;
                case 5:
                    if (target < 9 && target > 2)
                    {
                        if (line_1[target - 3] && line_1[target - 2] && line_1[target - 1] && line_1[target] && line_1[target + 1])
                        {
                            line_1[target - 3] = line_1[target - 2] = line_1[target - 1] = line_1[target] = line_1[target + 1] = false;
                            spine_building_(1, target - 3, dnditem);
                            line1_raycast_setactive(5, target - 3, dnditem);
                            return target - 3;
                        }
                    }
                    break;
            }
        }
        else if (Parent == 2)
        {
            switch (dnditem.width)
            {
                case 1:
                    if (line_2[target - 1] == true)
                    {
                        line_2[target - 1] = false;
                        spine_building_(2, target - 1, dnditem);
                        line2_raycast_setactive(1, target - 1,dnditem);
                        return target - 1;
                    }
                    break;
                case 2:
                    if (dir && target < 16)
                    {
                        if (line_2[target - 1] && line_2[target])
                        {
                            line_2[target - 1] = line_2[target] = false;
                            spine_building_(2, target - 1, dnditem);
                            line2_raycast_setactive(2, target - 1, dnditem);
                            return target - 1;
                        }
                    }
                    else if (!dir && target > 1)
                    {
                        if (line_2[target - 1] && line_2[target - 2])
                        {
                            line_2[target - 1] = line_2[target - 2] = false;
                            spine_building_(2, target - 2, dnditem);
                            line2_raycast_setactive(2, target - 2, dnditem);
                            return target - 2;
                        }
                    }
                    break;
                case 3:
                    if (target < 16 && target > 1)
                    {
                        if (line_2[target - 2] && line_2[target - 1] && line_2[target])
                        {
                            line_2[target - 2] = line_2[target - 1] = line_2[target] = false;
                            spine_building_(2, target - 2, dnditem);
                            line2_raycast_setactive(3, target - 2, dnditem);
                            return target - 2;
                        }
                    }
                    break;
                case 4:
                    if (dir && target < 15 && target > 1)
                    {
                        if (line_2[target - 1] && line_2[target] && line_2[target + 1] && line_2[target - 2])
                        {
                            line_2[target - 2] = line_2[target - 1] = line_2[target] = line_2[target + 1] = false;
                            spine_building_(2, target - 2, dnditem);
                            line2_raycast_setactive(4, target - 2, dnditem);
                            return target - 2;
                        }
                    }
                    if (!dir && target < 16 && target > 2)
                    {
                        if (line_2[target - 3] && line_2[target - 2] && line_2[target] && line_2[target - 1])
                        {
                            line_2[target - 3] = line_2[target - 2] = line_2[target] = line_2[target - 1] = false;
                            spine_building_(2, target - 3, dnditem);
                            line2_raycast_setactive(4, target - 3, dnditem);
                            return target - 3;
                        }
                    }
                    break;
                case 5:
                    if (target < 15 && target > 2)
                    {
                        if (line_2[target - 3] && line_2[target - 2] && line_2[target - 1] && line_2[target] && line_2[target + 1])
                        {
                            line_2[target - 3] = line_2[target - 2] = line_2[target - 1] = line_2[target] = line_2[target + 1] = false;
                            spine_building_(2, target - 3, dnditem);
                            line2_raycast_setactive(5, target - 3, dnditem);
                            return target - 3;
                        }
                    }
                    break;
            }
        }
        else if (Parent == 3)
        {
            switch (dnditem.width)
            {
                case 1:
                    if (line_3[target - 1] == true)
                    {
                        line_3[target - 1] = false;
                        spine_building_(3, target - 1, dnditem);
                        line3_raycast_setactive(1, target - 1, dnditem);
                        return target - 1;
                    }
                    break;
                case 2:
                    if (dir && target < 20)
                    {
                        if (line_3[target - 1] && line_3[target])
                        {
                            line_3[target - 1] = line_3[target] = false;
                            spine_building_(3, target - 1, dnditem);
                            line3_raycast_setactive(2, target - 1, dnditem);
                            return target - 1;
                        }
                    }
                    else if (!dir && target > 1)
                    {
                        if (line_3[target - 1] && line_3[target - 2])
                        {
                            line_3[target - 1] = line_3[target - 2] = false;
                            spine_building_(3, target - 2, dnditem);
                            line3_raycast_setactive(2, target - 2, dnditem);
                            return target - 2;
                        }
                    }
                    break;
                case 3:
                    if (target < 20 && target > 1)
                    {
                        if (line_3[target - 2] && line_3[target - 1] && line_3[target])
                        {
                            line_3[target - 2] = line_3[target - 1] = line_3[target] = false;
                            spine_building_(3, target - 2, dnditem);
                            line3_raycast_setactive(3, target - 2, dnditem);
                            return target - 2;
                        }
                    }
                    break;
                case 4:
                    if (dir && target < 19 && target > 1)
                    {
                        if (line_3[target - 1] && line_3[target] && line_3[target + 1] && line_3[target - 2])
                        {
                            line_3[target - 2] = line_3[target - 1] = line_3[target] = line_3[target + 1] = false;
                            spine_building_(3, target - 2, dnditem);
                            line3_raycast_setactive(4, target - 2, dnditem);
                            return target - 2;
                        }
                    }
                    if (!dir && target < 20 && target > 2)
                    {
                        if (line_3[target - 3] && line_3[target - 2] && line_3[target] && line_3[target - 1])
                        {
                            line_3[target - 3] = line_3[target - 2] = line_3[target] = line_3[target - 1] = false;
                            spine_building_(3, target - 3, dnditem);
                            line3_raycast_setactive(4, target - 3, dnditem);
                            return target - 3;
                        }
                    }
                    break;
                case 5:
                    if (target < 19 && target > 2)
                    {
                        if (line_3[target - 3] && line_3[target - 2] && line_3[target - 1] && line_3[target] && line_3[target + 1])
                        {
                            line_3[target - 3] = line_3[target - 2] = line_3[target - 1] = line_3[target] = line_3[target + 1] = false;
                            spine_building_(3, target - 3, dnditem);
                            line3_raycast_setactive(5, target - 3, dnditem);
                            return target - 3;
                        }
                    }
                    break;
            }
        }
        return -1;
    }
    void line1_raycast_setactive(int width, int target, Dnditem dnditem)
    {
        for (int i = 0; i < width; i++)
        {
            Color a = new Color(84 / 255f, 221 / 255f, 254 / 255f, 0);
            Image ti = line1.transform.GetChild(target + i).GetComponent<Image>();
            ti.color = a;

            line1.transform.GetChild(target + i).GetComponent<build_info>().index = dnditem.index_;
            line1.transform.GetChild(target + i).GetComponent<build_info>().width = dnditem.width;
            line1.transform.GetChild(target + i).GetComponent<build_info>().name = dnditem.spine_name;
            line1.transform.GetChild(target + i).GetComponent<build_info>().thema = dnditem.thema;
            line1.transform.GetChild(target + i).GetComponent<build_info>().target = target;
        }
    }
    void line2_raycast_setactive(int width, int target,Dnditem dnditem)
    {
        for (int i = 0; i < width; i++)
        {
            Color a = new Color(84 / 255f, 221 / 255f, 254 / 255f, 0);
            Image ti = line2.transform.GetChild(target + i).GetComponent<Image>();
            ti.color = a;
            line2.transform.GetChild(target + i).GetComponent<build_info>().index = dnditem.index_;
            line2.transform.GetChild(target + i).GetComponent<build_info>().width = dnditem.width;
            line2.transform.GetChild(target + i).GetComponent<build_info>().name = dnditem.spine_name;
            line2.transform.GetChild(target + i).GetComponent<build_info>().thema = dnditem.thema;
            line2.transform.GetChild(target + i).GetComponent<build_info>().target = target;
        }
    }
    void line3_raycast_setactive(int width, int target,Dnditem dnditem)
    {
        for (int i = 0; i < width; i++)
        {
            Color a = new Color(84 / 255f, 221 / 255f, 254 / 255f, 0);
            Image ti = line3.transform.GetChild(target + i).GetComponent<Image>();
            ti.color = a;

            line3.transform.GetChild(target + i).GetComponent<build_info>().index = dnditem.index_;
            line3.transform.GetChild(target + i).GetComponent<build_info>().width = dnditem.width;
            line3.transform.GetChild(target + i).GetComponent<build_info>().name = dnditem.spine_name;
            line3.transform.GetChild(target + i).GetComponent<build_info>().thema = dnditem.thema;
            line3.transform.GetChild(target + i).GetComponent<build_info>().target = target;
        }
    }
    void spine_building_(int parent, int target, Dnditem dnditem)
    {

        GameObject GO;
        SkeletonGraphic skg;
        switch (parent)
        {

            case 1:
                GO = view1.transform.GetChild(target).gameObject;
                skg = GO.GetComponent<SkeletonGraphic>();
                skg.skeletonDataAsset = Resources.Load("building/" + dnditem.thema + "/" + dnditem.spine_name + "_1") as SkeletonDataAsset;
                skg.startingAnimation = sky_check();
                skg.startingLoop = true;
                skg.timeScale = 1f;
                skg.Initialize(true);
                GO.SetActive(true);
                break;
            case 2:
                GO = view2.transform.GetChild(target).gameObject;
                skg = GO.GetComponent<SkeletonGraphic>();
                skg.skeletonDataAsset = Resources.Load("building/" + dnditem.thema + "/" + dnditem.spine_name + "_2") as SkeletonDataAsset;
                skg.startingAnimation = sky_check();
                skg.startingLoop = true;
                skg.timeScale = 1f;
                skg.Initialize(true);
                GO.SetActive(true);
                break;
            case 3:
                GO = view3.transform.GetChild(target).gameObject;
                skg = GO.GetComponent<SkeletonGraphic>();
                skg.skeletonDataAsset = Resources.Load("building/" + dnditem.thema + "/" + dnditem.spine_name + "_3") as SkeletonDataAsset;
                skg.startingAnimation = sky_check();
                skg.startingLoop = true;
                skg.timeScale = 1f;
                skg.Initialize(true);
                GO.SetActive(true);
                break;
        }
    }
    string sky_check()
    {
        string s = "_v3_l3_o";
        if (Sky_TYPE == sky_type.blue)
        {
            return "b" + s;
        }
        if (Sky_TYPE == sky_type.red)
        {
            return "r" + s;
        }
        if (Sky_TYPE == sky_type.yellow)
        {
            return "y" + s;
        }
        return null;
    }
    public void demolish()
    {
        int de = int.Parse(targetObj.transform.parent.name);
        GameObject go;
        switch (de)
        {
            case 1:
                for (int i = target_check_value; i < target_check_value + width; i++)
                { 
                    line_1[i] = true;
                    line1.transform.GetChild(i).GetComponent<build_info>().reset();
                    if (line1.transform.GetChild(i).childCount != 0)
                    {
                        Destroy(line1.transform.GetChild(i).GetChild(0).gameObject);
                    }
                    Color a = new Color(84 / 255f, 221 / 255f, 254 / 255f, 1f);
                    Image ti = line1.transform.GetChild(i).GetComponent<Image>();
                    ti.color = a;
                }
                go = view1.transform.GetChild(target_check_value).gameObject;
                go.gameObject.SetActive(false);
                break;
            case 2:
                for (int i = target_check_value; i < target_check_value + width; i++)
                {
                    line_2[i] = true;
                    line2.transform.GetChild(i).GetComponent<build_info>().reset();
                    if (line2.transform.GetChild(i).childCount != 0)
                    {
                        Destroy(line2.transform.GetChild(i).GetChild(0).gameObject);
                    }
                    Color a = new Color(84 / 255f, 221 / 255f, 254 / 255f, 1f);
                    Image ti = line2.transform.GetChild(i).GetComponent<Image>();
                    ti.color = a;
                }
                go = view2.transform.GetChild(target_check_value).gameObject;
                go.gameObject.SetActive(false);
                break;
            case 3:
                for (int i = target_check_value; i < target_check_value + width; i++)
                {
                    line_3[i] = true;
                    line3.transform.GetChild(i).GetComponent<build_info>().reset();
                    if (line3.transform.GetChild(i).childCount != 0)
                    {
                        Destroy(line3.transform.GetChild(i).GetChild(0).gameObject);
                        go = view3.transform.GetChild(i).gameObject;
                        go.gameObject.SetActive(false);
                    }
                    Color a = new Color(84 / 255f, 221 / 255f, 254 / 255f, 1f);
                    Image ti = line3.transform.GetChild(i).GetComponent<Image>();
                    ti.color = a;
                }
                go = view3.transform.GetChild(target_check_value).gameObject;
                go.gameObject.SetActive(false);
                break;
        }
    }
    public void sky_change()
    {

        string l1 = "_v1_l3_o";
        string l2 = "_v2_l3_b";
        string l3 = "_v3_l3_c";
        SkeletonGraphic skg;
        GameObject go;
        if (Sky_TYPE == sky_type.blue)
        {
            for (int i = 0; i < 10; i++)
            {

                string ani_name = "b" + l1;
                go = view1.transform.GetChild(i).gameObject;
                skg = go.GetComponent<SkeletonGraphic>();
                if (skg.skeletonDataAsset != null)
                skg.AnimationState.SetAnimation(0, ani_name, true);
            }
            for (int i = 0; i < 16; i++)
            {
                string ani_name = "b" + l2;
                go = view2.transform.GetChild(i).gameObject;
                skg = go.GetComponent<SkeletonGraphic>();
                if (skg.skeletonDataAsset != null)
                    skg.AnimationState.SetAnimation(0, ani_name, true);
            }
            for (int i = 0; i < 20; i++)
            {
                string ani_name = "b" + l3;
                go = view3.transform.GetChild(i).gameObject;
                skg = go.GetComponent<SkeletonGraphic>();
                if (skg.skeletonDataAsset != null)
                    skg.AnimationState.SetAnimation(0, ani_name, true);
            }
            skg =      water_.GetComponent<SkeletonGraphic>();
            skg.AnimationState.SetAnimation(0, "water_b",true);
            return;
        }
        if (Sky_TYPE == sky_type.red)
        {
            for (int i = 0; i < 10; i++)
            {
                string ani_name = "r" + l1;
                go = view1.transform.GetChild(i).gameObject;
                skg = go.GetComponent<SkeletonGraphic>();
                if (skg.skeletonDataAsset != null)
                    skg.AnimationState.SetAnimation(0, ani_name, true);
            }
            for (int i = 0; i < 16; i++)
            {
                string ani_name = "r" + l2;
                go = view2.transform.GetChild(i).gameObject;
                skg = go.GetComponent<SkeletonGraphic>();
                if (skg.skeletonDataAsset != null)
                    skg.AnimationState.SetAnimation(0, ani_name, true);
            }
            for (int i = 0; i < 20; i++)
            {
                string ani_name = "r" + l3;
                go = view3.transform.GetChild(i).gameObject;
                skg = go.GetComponent<SkeletonGraphic>();
                if (skg.skeletonDataAsset != null)
                    skg.AnimationState.SetAnimation(0, ani_name, true);
            }
            skg = water_.GetComponent<SkeletonGraphic>();
            skg.AnimationState.SetAnimation(0, "water_o", true);
            return;
        }
        if (Sky_TYPE == sky_type.yellow)
        {
            for (int i = 0; i < 10; i++)
            {
                string ani_name = "y" + l1;
                go = view1.transform.GetChild(i).gameObject;
                skg = go.GetComponent<SkeletonGraphic>();
                if (skg.skeletonDataAsset != null)
                    skg.AnimationState.SetAnimation(0, ani_name, true);
            }
            for (int i = 0; i < 16; i++)
            {
                string ani_name = "y" + l2;
                go = view2.transform.GetChild(i).gameObject;
                skg = go.GetComponent<SkeletonGraphic>();
                if (skg.skeletonDataAsset != null)
                    skg.AnimationState.SetAnimation(0, ani_name, true);
            }
            for (int i = 0; i < 20; i++)
            {
                string ani_name = "y" + l3;
                go = view3.transform.GetChild(i).gameObject;
                skg = go.GetComponent<SkeletonGraphic>();
                if (skg.skeletonDataAsset != null)
                    skg.AnimationState.SetAnimation(0, ani_name, true);
            }
            skg = water_.GetComponent<SkeletonGraphic>();
            skg.AnimationState.SetAnimation(0, "water_y", true);
            return;
        }
    }
}