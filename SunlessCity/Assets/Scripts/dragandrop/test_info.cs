using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Numerics;
public class test_info : MonoBehaviour {


    public ItemDB idb;

    public int index;
    public int width_;
    public string name_;
    public int level;
    public BigInteger click_ins;
    public BigInteger auto_ins;
    public string thema;
  //  int count;

    public void update_info()
    {
        width_ = idb.items[index - 1].width;
        click_ins = idb.items[index - 1].click_ins;
        auto_ins = idb.items[index - 1].auto_ins;
        name_ = idb.items[index - 1].Spine;
        level = idb.items[index - 1].level;
    }
}
