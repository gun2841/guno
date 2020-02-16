using UnityEngine;
using System.Collections;

public class KinectControl : MonoBehaviour
{
    #region value
    public enum BoneMask
    {
        None = 0x0,
        Hip_Center = 0x1,
        Spine = 0x2,
        Shoulder_Center = 0x4,
        Head = 0x8,
        Shoulder_Left = 0x10,
        Elbow_Left = 0x20,
        Wrist_Left = 0x40,
        Hand_Left = 0x80,
        Shoulder_Right = 0x100,
        Elbow_Right = 0x200,
        Wrist_Right = 0x400,
        Hand_Right = 0x800,
        Hip_Left = 0x1000,
        Knee_Left = 0x2000,
        Ankle_Left = 0x4000,
        Foot_Left = 0x8000,
        Hip_Right = 0x10000,
        Knee_Right = 0x20000,
        Ankle_Right = 0x40000,
        Foot_Right = 0x80000,
        All = 0xFFFFF,
        Torso = 0x10000F, //the leading bit is used to force the ordering in the editor
        Left_Arm = 0x1000F0,
        Right_Arm = 0x100F00,
        Left_Leg = 0x10F000,
        Right_Leg = 0x1F0000,
        R_Arm_Chest = Right_Arm | Spine,
        No_Feet = All & ~(Foot_Left | Foot_Right),
        UpperBody = Shoulder_Center | Head | Shoulder_Left | Elbow_Left | Wrist_Left | Hand_Left |
        Shoulder_Right | Elbow_Right | Wrist_Right | Hand_Right

    }
    public SkeletonWrapper sw;
    public int player;
    public float scale = 1.0f;
    public BoneMask Mask = BoneMask.All;
    public Vector3[] _boneposition;
    public Vector3 abc1 = new Vector3(1, 0);
    public Vector3 abc2;
    public int a = 0;
    public int vertical;
    bool movebool;
    int speedcheck = 1;
    bool blspeed = false;
    bool backcheck = false;

    private Home_Button script1;
    #endregion
    // Use this for initialization
    void Start()
    {
       _boneposition = new Vector3[(int)Kinect.NuiSkeletonPositionIndex.Count];
    }
    // Update is called once per frame
    void Update()
    {
        #region kinect initialize
        if (player == -1)
            return;
        if (sw.pollSkeleton())
        {
            for (int ii = 0; ii < (int)Kinect.NuiSkeletonPositionIndex.Count; ii++)
            {
                //_bonePos[ii] = sw.getBonePos(ii);
                if (((uint)Mask & (uint)(1 << ii)) > 0)
                {
                    //_bones[ii].transform.localPosition = sw.bonePos[player,ii];
                    _boneposition[ii] = new Vector3(
                        sw.bonePos[player, ii].x * scale,
                        sw.bonePos[player, ii].y * scale,
                        sw.bonePos[player, ii].z * scale);
                }
            }
        }
        int Shoulderright = (int)Kinect.NuiSkeletonPositionIndex.ShoulderRight; // 오른쪽 어깨
        int Shoulderleft = (int)Kinect.NuiSkeletonPositionIndex.ShoulderLeft; // 왼쪽 어깨
        int hipcenter = (int)Kinect.NuiSkeletonPositionIndex.HipCenter; // 엉덩이
        int shoulder = (int)Kinect.NuiSkeletonPositionIndex.ShoulderCenter; // 어ㅐ
        int head = (int)Kinect.NuiSkeletonPositionIndex.Head; //머리
        int lefthand = (int)Kinect.NuiSkeletonPositionIndex.HandLeft;
        int righthand = (int)Kinect.NuiSkeletonPositionIndex.HandRight;
        #endregion

        if (_boneposition[lefthand].y - _boneposition[shoulder].y > 0.3f)
        {
            Debug.Log("스탑앤 멈춤");
            transform.SendMessage("movechange");
        }
        else if (_boneposition[shoulder].z < _boneposition[hipcenter].z - 0.2f)
        {
            if (backcheck == false)
                transform.SendMessage("backstepcheck");
        }
        else if (_boneposition[righthand].y - _boneposition[shoulder].y > 0.3f)
        {
            Debug.Log("달리기");
            if (blspeed == false)
                transform.SendMessage("speedup");
        }
        else
        {
                transform.SendMessage("speeddown");
                blspeed = false;
                transform.SendMessage("antiback");
                backcheck = false;
  }
        if (_boneposition[head].x - _boneposition[hipcenter].x < -0.25 )
        {
            if (movebool == true)
            {
                transform.SendMessage("RotateView", -1);
            }
            movebool = false;
            Debug.Log("Left");
        }
        else if ((_boneposition[head].x - _boneposition[hipcenter].x > 0.25))
        {
            if (movebool == true)
            {
                transform.SendMessage("RotateView", 1);
            }
            movebool = false;
            Debug.Log("Right");
        }
        else
        {
            movebool = true;
        }


        if ((_boneposition[righthand].y - _boneposition[shoulder].y > 0.3f) && (
           _boneposition[lefthand].y - _boneposition[shoulder].y > 0.3f))
        {
            script1 = GameObject.Find("Home").GetComponent<Home_Button>();
            script1.OnClick();
            Debug.Log("처음 화면으로!");
        }
    }
}