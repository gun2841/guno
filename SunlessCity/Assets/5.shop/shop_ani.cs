using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class shop_ani : MonoBehaviour {
    public Animation shop_a;
    public shop_top_text stt;
    int cur_ani;
    public AudioSource aud;
    void audplay()
    {
        aud.Play();
    }
    void Start()
    {
        cur_ani = 0;
    }
    public void build_gain_on()
    {
        if (cur_ani == 1)
            return;
        stt.change_text(0);
        cur_ani = 1;
        shop_a.Play("build_gain_on"); audplay();
    }
    public void obj_gain_on()
    {
        if (cur_ani == 2)
            return;
        stt.change_text(5);
        cur_ani = 2;
        shop_a.Play("obj_gain_on"); audplay();
    }
    public void package_on()
    {
        if (cur_ani == 3)
            return;
        stt.change_text(6);
        cur_ani = 3;
        shop_a.Play("package_on"); audplay();
    }
    public void sector_on()
    {
        if (cur_ani == 4)
            return;
        stt.change_text(7);
        cur_ani = 4;
        shop_a.Play("sector_on"); audplay();
    }
    public void skin_gain_on()
    {
        if (cur_ani == 5)
            return;
        stt.change_text(4);
        cur_ani = 5;
        shop_a.Play("skin_gain_on"); audplay();
    }
    public void sky_gain_on()
    {
        if (cur_ani == 6)
            return;
        cur_ani = 6;
        stt.change_text(3);
        shop_a.Play("sky_gain_on"); audplay();
    }
    public void ticket_on()
    {
        if (cur_ani == 7)
            return;
        stt.change_text(1);
        cur_ani = 7;
        shop_a.Play("ticket_on"); audplay();
    }
}
