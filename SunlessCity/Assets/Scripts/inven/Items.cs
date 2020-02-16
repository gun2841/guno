using UnityEngine;
using System.Numerics;
[System.Serializable]
public class Items
{
    public string name;
    public int level;
    public int count; // 보유량

    public int width;
    public BigInteger click_ins;
    public BigInteger auto_ins;

    public Thema thema;

     public string Spine;

    public enum Thema
    {
        KR, JP, NA, sa, eu, chn , sf
    }

    public Items(string Name, int Level, int Width, int Count, string click, string auto, int n, string spine)
    {
        this.name = Name;
        this.level = Level;
        this.width = Width;
        this.count = Count;
        this.click_ins = BigInteger.Parse(click);
        this.auto_ins = BigInteger.Parse(auto);
        this.thema = (Thema)n;

        this.Spine = spine;

    }
    public void level_up(int click_ins_a, int click_ins_b, int auto_ins_a, int auto_ins_b)
    {
        level++;
        ins_up(click_ins_a, click_ins_b, auto_ins_a, auto_ins_b);
    }
    void ins_up(int click_ins_a, int click_ins_b, int auto_ins_a, int auto_ins_b)
    {
        click_ins = 1 + (click_ins_a + level) * (click_ins_b * click_ins) / 10;
        auto_ins = 1 + (auto_ins_a + level * 10) * (auto_ins_b * auto_ins) / 10;
    }
}