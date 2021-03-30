using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class edit_ani : MonoBehaviour {
    public Animation edit_a;

    public AudioSource aud;
    void audplay()
    {
        aud.Play();
    }
    int cur_ani;
	void Start () {
        cur_ani = 0;
	}
    public void build_edit_on()
    {
        if (cur_ani == 1)
            return;
        edit_a.Play("build_edit_on"); audplay();
        cur_ani = 1;
    }
    public void sky_edit_on()
    {
        if (cur_ani == 2)
            return;
        edit_a.Play("sky_edit_on"); audplay();
        cur_ani = 2;
    }
    public void skin_edit_on()
    {
        if (cur_ani == 3)
            return;
        edit_a.Play("skin_edit_on"); audplay();
        cur_ani = 3;
    }
    public void obj_edit_on()
    {
        if (cur_ani == 4)
            return;
        edit_a.Play("obj_edit_on"); audplay();
        cur_ani = 4;
    }
    public void sector_edit_on()
    {
        if (cur_ani == 5)
            return;
        edit_a.Play("sector_edit_on"); audplay();
        cur_ani = 5;
    }
    public void edit_out()
    {
        cur_ani = 0;
        edit_a.Play("edit_out"); audplay();
    }
}
