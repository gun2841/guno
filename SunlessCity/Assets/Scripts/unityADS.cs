using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Advertisements;
public class unityADS : MonoBehaviour {
    private const string android_game_id = "2701782";
    private const string ios_game_id = "2701781";

    private const string rewarded_video_id = "rewardedVideo";
	// Use this for initialization
	void Start () {
        Initialize();
	}
	private void Initialize() {
#if UNITY_ANDROID
         Advertisement.Initialize(android_game_id);
#elif UNITY_IOS
       Advertisement.Initialize(ios_game_id);
#endif
    }
    public void ShowRewardedAd() {
        if (Advertisement.IsReady(rewarded_video_id)) {
            var option = new ShowOptions { resultCallback = HandleShowResult };
            Advertisement.Show(rewarded_video_id, option);
        }
    }
    private void HandleShowResult(ShowResult result) {
        switch(result) {
            case ShowResult.Finished: {
                    Debug.Log("success");
                    //시청완료


                    break;
                }
            case ShowResult.Skipped: {
                    Debug.Log("skip");
                    //광고스킵

                    break;
                }
            case ShowResult.Failed: {
                    Debug.Log("fail");
                    //실패


                    break;
                }
        }
    }
}
