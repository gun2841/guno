using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Mono.Data.Sqlite;
using System.Data;
using Spine.Unity;
public class inventory : MonoBehaviour
{
    string sql;
    string thema;
    public int id;
    public ItemDB idb;
    public Money moneymgr;

    #region variable
    Color on_color = new Color(254 / 255f, 188 / 255f, 85 / 255f, 1f);
    Color off_color = new Color(84 / 255f, 221 / 255f, 254 / 255f);
    public Sprite[] Korea;
    public Sprite[] Japan;
    public Sprite[] USA;
    public Sprite[] SF;
    [Header("build-inventory")]
    public GameObject Content;
    public GameObject btn;
    Image pre_btn;


    [Header("inventory-")]
    public GameObject spine_obj;
    public Text show_name;
    public Text show_level;
    public Text show_thema;
    public GameObject show_explain;
    public Text width;
    public Image before_btn;
    public Image now_btn;
    #endregion

    #region 디비
    IDbConnection dbconn;
    IDbCommand dbcmd;
    IDataReader reader;
    #endregion
    void Start()
    {

        spine_obj.SetActive(false);
        pre_btn = btn.transform.GetChild(1).GetComponent<Image>();
        pre_btn.color = on_color;
        check_target("한국");
    }
    void DBconn()
    {
        int index = 0;
        int first = 0, end = 0;

        switch (thema)
        {
            case "ALL":
                return;
            case "KR":
                first = 0;
                index = 1; end = 23;
                break;
            case "JP":
                first = 23; end = 42;
                index = 2;
                break;
            case "NA":
                first = 42; end = 60;
                index = 3;
                break;
            case "SF":
                first = 117; end = 137;
                index = 4;
                break;
        }

        for (int i = 1; i < 25; i++)
        {
            string objName = "/MainCanvas/Shop_Setting_inven/inven/build_tap/grid_show/Viewport/Content/guide_" + i;
            GameObject target = GameObject.Find(objName);
            if (first + i > end)
            {
                target.SetActive(false);
            }
            else
                switch (index)
                {
                    case 1:
                        target.transform.GetChild(0).GetComponent<Image>().sprite = Korea[i - 1];
                        target.transform.GetChild(1).GetComponent<Text>().text = idb.items[i + first - 1].name;
                        target.transform.GetChild(2).GetComponent<Text>().text = "Lv " + idb.items[i + first - 1].level.ToString();
                        target.transform.GetChild(3).GetComponent<Text>().text = idb.items[i + first - 1].count.ToString();
                        if (idb.items[i + first - 1].count == 0)
                        {
                            target.transform.GetChild(4).gameObject.SetActive(true);
                        }
                        else
                            target.transform.GetChild(4).gameObject.SetActive(false);
                        target.SetActive(true);
                        break;
                    case 2:
                        target.transform.GetChild(0).GetComponent<Image>().sprite = Japan[i - 1];
                        target.transform.GetChild(1).GetComponent<Text>().text = idb.items[i + first - 1].name;
                        target.transform.GetChild(2).GetComponent<Text>().text = "Lv " + idb.items[i + first - 1].level.ToString();
                        target.transform.GetChild(3).GetComponent<Text>().text = idb.items[i + first - 1].count.ToString();
                        if (idb.items[i + first - 1].count == 0)
                        {
                            target.transform.GetChild(4).gameObject.SetActive(true);
                        }
                        else
                            target.transform.GetChild(4).gameObject.SetActive(false);

                        target.SetActive(true);
                        break;
                    case 3:
                        target.transform.GetChild(0).GetComponent<Image>().sprite = USA[i - 1];
                        target.transform.GetChild(1).GetComponent<Text>().text = idb.items[i + first - 1].name;
                        target.transform.GetChild(2).GetComponent<Text>().text = "Lv " + idb.items[i + first - 1].level.ToString();
                        target.transform.GetChild(3).GetComponent<Text>().text = idb.items[i + first - 1].count.ToString();
                        if (idb.items[i + first - 1].count == 0)
                        {
                            target.transform.GetChild(4).gameObject.SetActive(true);
                        }
                        else
                            target.transform.GetChild(4).gameObject.SetActive(false);
                        target.SetActive(true);
                        break;
                    case 4:
                        target.transform.GetChild(0).GetComponent<Image>().sprite = SF[i - 1];
                        target.transform.GetChild(1).GetComponent<Text>().text = idb.items[i + first - 1].name;
                        target.transform.GetChild(2).GetComponent<Text>().text = "Lv " + idb.items[i + first - 1].level.ToString();
                        target.transform.GetChild(3).GetComponent<Text>().text = idb.items[i + first - 1].count.ToString();
                        if (idb.items[i + first - 1].count == 0)
                        {
                            target.transform.GetChild(4).gameObject.SetActive(true);
                        }
                        else
                            target.transform.GetChild(4).gameObject.SetActive(false);
                        target.SetActive(true);
                        break;
                    default:
                        //  target.transform.GetComponent<Image>().sprite = null;
                        break;
                }
        }
    }
    #region inventory
    public void themaChange(string str)
    {
        if (thema == str)
            return;

        show_name.text = "";
        show_level.text = "Lv ";
        show_thema.text = "";

        show_explain.GetComponentInChildren<Text>().text = "";
        width.text = "";

        show_explain.gameObject.SetActive(false);
        show_explain.GetComponentInChildren<Text>().color = new Color(1f, 1f, 1f, 0f);
        spine_obj.SetActive(false);
        thema = str;
        DBconn();
    }
    public void color_change(Image im)
    {
        if (im == now_btn)
            return;
        before_btn = now_btn;
        before_btn.color = off_color;
        now_btn = im;
        now_btn.color = on_color;

    }
    public void select_building(Text target)
    {
        show_explain.gameObject.SetActive(false);


        if (target.text == "")
        { spine_obj.SetActive(false); return; }

        string conn = "";

        if (Application.platform == RuntimePlatform.Android)
        {
            conn = "URI=file:" + Application.persistentDataPath + "/buildDb.db";
        }
        else
        {
            conn = "URI=file:" + Application.streamingAssetsPath + "/buildDB.db";
        }


        dbconn = (IDbConnection)new SqliteConnection(conn);
        dbconn.Open();
        dbcmd = dbconn.CreateCommand();
        sql = "SELECT * FROM info WHERE thema = " + '"' + thema + '"' + " AND Name = "
              + '"' + target.text + '"';

        dbcmd.CommandText = sql;
        reader = dbcmd.ExecuteReader();
        reader.Read();


        // 스파인 셋팅
        SkeletonGraphic skg;
        skg = spine_obj.GetComponent<SkeletonGraphic>();
        skg.skeletonDataAsset = Resources.Load("building/" + thema + "/" + reader.GetString(9)) as SkeletonDataAsset;
        skg.startingAnimation = "b_v1_l3_b";
        skg.startingLoop = true;
        skg.timeScale = 1f;
        skg.Initialize(true);

        if (reader.GetInt32(6) == 0) // 보유하고 있지 않은 경우
        {
            show_name.text = "????";
            show_thema.text = "????";
            show_level.text = "Lv ??";
            show_explain.GetComponentInChildren<Text>().text = "???\n????\n?????";
            width.text = "??";

            spine_obj.GetComponent<SkeletonGraphic>().color = new Color(0f, 0f, 0f);
            spine_obj.transform.GetChild(0).gameObject.SetActive(true);

        }
        else /// 보유하고있을경우
        {
            show_name.text = reader.GetString(1);
            show_level.text = "Lv " + reader.GetInt32(5).ToString(); ;
            show_thema.text = reader.GetString(3);
            show_explain.GetComponentInChildren<Text>().text = reader.GetString(4);
            width.text = reader.GetInt32(2).ToString();

            spine_obj.GetComponent<SkeletonGraphic>().color = new Color(1f, 1f, 1f);
            spine_obj.transform.GetChild(0).gameObject.SetActive(false);
        }

        float scale = skg.skeletonDataAsset.scale * 100;

        spine_obj.GetComponent<RectTransform>().anchoredPosition = new Vector2(-32 * reader.GetInt32(2) * scale, -210);

        spine_obj.SetActive(true);

        reader.Close();
        reader = null;
        dbcmd.Dispose(); dbcmd = null; dbconn.Close(); dbconn = null;
    }
    public void detail_click()
    {
        if (spine_obj.activeSelf == true)
        {
            if (show_explain.activeSelf == false)
            {
                show_explain.gameObject.SetActive(true);
                show_explain.GetComponent<Animation>().Play("explain_ani");
            }
            else
            {
                show_explain.GetComponentInChildren<Text>().color = new Color(1f, 1f, 1f, 0f);
                show_explain.gameObject.SetActive(false);
            }
        }
    }
    #endregion

    #region build-inventory
    public void click_btn(Image arg)
    {
        if (pre_btn == arg)
            return;
        pre_btn.color = off_color;
        arg.color = on_color;
        check_target(arg.transform.GetChild(0).GetComponent<Text>().text);
        pre_btn = arg;
        //

    }
    void check_target(string send)
    {
        int first = 0, end = 0;

        switch (send)
        {
            case "한국":
                first = 1;
                end = 23;
                break;
            case "일본":
                first = 24; end = 42;
                break;
            case "미국":
                first = 43; end = 60;
                break;
            case "SF":
                first = 118; end = 137;
                break;
        }

        for (int i = 0; i < 25; i++)
        {
            if (i + first > end)
            {
                Content.transform.GetChild(i).gameObject.SetActive(false);
                continue;
            }
            switch (send)
            {
                case "한국":
                    if (idb.items[i].count != 0)
                    {
                        Content.transform.GetChild(i).GetComponent<test_info>().index = i + first;
                        Content.transform.GetChild(i).GetComponent<test_info>().update_info();
                        Content.transform.GetChild(i).GetComponent<test_info>().thema = "KR";
                        Content.transform.GetChild(i).gameObject.SetActive(true);
                        Content.transform.GetChild(i).GetChild(0).GetChild(0).GetComponent<Image>().sprite = Korea[i];
                        Content.transform.gameObject.SetActive(true);
                    }
                    break;
                case "일본":
                    if (idb.items[i].count != 0)
                    {
                        Content.transform.GetChild(i).GetComponent<test_info>().index = i + first;
                        Content.transform.GetChild(i).GetComponent<test_info>().update_info();
                        Content.transform.GetChild(i).GetComponent<test_info>().thema = "JP";
                        Content.transform.GetChild(i).gameObject.SetActive(true);
                        Content.transform.GetChild(i).GetChild(0).GetChild(0).GetComponent<Image>().sprite = Japan[i];
                        Content.transform.gameObject.SetActive(true);
                    }
                    break;
                case "EU":
                    break;
                case "미국":
                    if (idb.items[i].count != 0)
                    {
                        Content.transform.GetChild(i).GetComponent<test_info>().index = i + first;
                        Content.transform.GetChild(i).GetComponent<test_info>().update_info();
                        Content.transform.GetChild(i).GetComponent<test_info>().thema = "NA";
                        Content.transform.GetChild(i).gameObject.SetActive(true);
                        Content.transform.GetChild(i).GetChild(0).GetChild(0).GetComponent<Image>().sprite = USA[i];
                        Content.transform.gameObject.SetActive(true);
                    }
                    break;
                case "SA":
                    break;
                case "CH":
                    break;
                case "SF":
                    if (idb.items[i].count != 0)
                    {
                        Content.transform.GetChild(i).GetComponent<test_info>().index = i + first;
                        Content.transform.GetChild(i).GetComponent<test_info>().update_info();
                        Content.transform.GetChild(i).GetComponent<test_info>().thema = "SF";
                        Content.transform.GetChild(i).gameObject.SetActive(true);
                        Content.transform.GetChild(i).GetChild(0).GetChild(0).GetComponent<Image>().sprite = SF[i];
                        Content.transform.gameObject.SetActive(true);
                    }
                    break;
                case "ETC":
                    break;
            }

        }
    }
    #endregion

    #region shop
    public void gain(int idx)
    {
        idb.items[idx].count++;
        Debug.Log(idb.items[idx].name);
    }
    #endregion


}