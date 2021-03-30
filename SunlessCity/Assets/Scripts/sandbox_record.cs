using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using AppAdvisory.VSGIF;
public class sandbox_record : MonoBehaviour {

    bool check = false;
    public void click_event() {
        if (check) {
            check = false;
            record_save();
        }
        else {
            record_start();
            check = true;
        }
        }
    void record_start() {
        Record.DORec();
    }
    void record_save() {
        Record.DOSave();
    }

}
