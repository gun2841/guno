using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class inven_ani : MonoBehaviour
{
    public Animation inven_a;
    public AudioSource aud;
    int cur_ani;
    void Start()
    {
        cur_ani = 0;
    }
    public void build_on()
    {
        if (cur_ani == 1)
            return;
        cur_ani = 1;
        inven_a.Play("build_on"); audplay();
    }
    public void sky_on()
    {
        if (cur_ani == 2)
            return;
        cur_ani = 2;
        inven_a.Play("sky_on"); audplay();
    }
    public void skin_on()
    {
        if (cur_ani == 3)
            return;
        cur_ani = 3; inven_a.Play("skin_on"); audplay();
    }
    public void obj_on()
    {
        if (cur_ani == 4)
            return;
        cur_ani = 4; inven_a.Play("obj_on"); audplay();
    }
    public void sector_on()
    {
        if (cur_ani == 5)
            return;
        cur_ani = 5; inven_a.Play("sector_on"); audplay();
    }
    void audplay()
    {
        aud.Play();
    }
}
