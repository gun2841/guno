using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class main_system : MonoBehaviour
{
    private static main_system _instance;
    public static main_system instance
    {
        get
        {
            if (_instance == null)
            {
                GameObject go = GameObject.Find("MAINSYSTEM");
                if (go == null)
                {
                    go = new GameObject("MAINSYSTEM");
                }
                _instance = go.GetComponent<main_system>();
                if (_instance == null)
                {
                    _instance = go.AddComponent<main_system>();
                }
                DontDestroyOnLoad(go);
            }
            return _instance;
        }
    }

    public GameObject _basic;
    public AudioSource aud;

    public GameObject LQ;
    public GameObject SSI;

    public GameObject edit_mode;
    public Animation viewing_ani;


    bool edit_mode_check;

    void Start()
    {
        edit_mode_check = false;
    }
    public void LQ_on(int index)
    {
        audPlay();
        switch (index)
        {
            case 1:
                LQ.GetComponent<Animation>().Play("Lv_on");
                break;
            case 2:
                LQ.GetComponent<Animation>().Play("Quest_on");
                break;
            default:
                break;
        }
    }
    public void Level_quest_out()
    {
        audPlay();
        LQ.GetComponent<Animation>().Play("LQ_out");
    }
    public void Edit_on()
    {
        audPlay();
        if (edit_mode.GetComponent<Animation>().isPlaying)
            return;
            if (edit_mode_check == false)
        {
            edit_mode_check = true;
            edit_mode.GetComponent<Animation>().Play("edit_mode_on");
        }
        else if ( edit_mode_check == true) 
        {
            edit_mode_check = false;
            edit_mode.GetComponent<Animation>().Play("edit_mode_off");
        }
    }
    public void SSI_on(int index)
    {
        audPlay();
        switch (index)
        {
            case 1:
                SSI.GetComponent<Animation>().Play("Shop_on");
                break;
            case 2:
                SSI.GetComponent<Animation>().Play("Inven_on");
                break;
            case 3:
                SSI.GetComponent<Animation>().Play("Setting_on");
                break;
            default:
                break;
        }
    }
    public void SSI_out()
    {
        audPlay();
        SSI.GetComponent<Animation>().Play("SSI_off");
    }
    public void View_on()
    {
        audPlay();
        viewing_ani.Play("view_on");
    }
    public void View_off()
    {
        audPlay();
        viewing_ani.Play("view_off");
    }
    void audPlay()
    {
        aud.Play();
    }
}