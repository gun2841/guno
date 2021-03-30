using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
public class LoadingScene : MonoBehaviour {

    public static string nextScene;

    [SerializeField]
    Image progressbar = null;
    [SerializeField]
    Text percent = null;
    // Use this for initialization
    void Start() {
        StartCoroutine(LoadScene());
    }
    string nextSceneName;
    public static void LoadScene(string sceneName) {
        nextScene = sceneName;
        SceneManager.LoadScene("load");
    }
    IEnumerator LoadScene() {
        yield return null;
        AsyncOperation op = SceneManager.LoadSceneAsync(nextScene);
        op.allowSceneActivation = false;

        float timer = 0.0f;
        while (!op.isDone) {
            yield return null;
            timer += Time.deltaTime;
 {
                Debug.Log(timer);
                progressbar.fillAmount = Mathf.Lerp(progressbar.fillAmount, op.progress, timer);
                percent.text = Mathf.Lerp(progressbar.fillAmount, 1f, timer).ToString();
                if (progressbar.fillAmount >= op.progress) {
                    timer = 0f;
                }
            }
        }
    }
}
