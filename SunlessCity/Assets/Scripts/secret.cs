using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Data;
using Mono.Data.Sqlite;
using System.IO;
public class secret : MonoBehaviour {
    public int count = 0;
    public Money my;
    #region variable
    IDbConnection dbconn;
    IDbCommand dbcmd;
    IDataReader reader;

    string sql;
    #endregion

    void OnEnable()
    {
        Screen.SetResolution(1920, 1080, true);

        string filepath = string.Empty;
        Debug.Log(Application.platform);
        if (Application.platform == RuntimePlatform.Android)
        {
            filepath = Application.persistentDataPath + "/buildDB.db";
            if(!File.Exists(filepath))
            {
                WWW loadDb = NewMethod();
                loadDb.bytesDownloaded.ToString();

                while (!loadDb.isDone) { }
                File.WriteAllBytes(filepath, loadDb.bytes);
            }
            else
            {
                WWW loadDb = NewMethod();
                loadDb.bytesDownloaded.ToString();

                while (!loadDb.isDone) { }
                File.WriteAllBytes(filepath, loadDb.bytes);
            }
        }
        else
        {
            filepath = Application.dataPath + "/buildDB.db";
            if (!File.Exists(filepath))
            {
                File.Copy(Application.streamingAssetsPath + "/buildDB.db", filepath);
            }
            else
            {
                
            }
        }
    }

    private static WWW NewMethod()
    {
        return new WWW("jar:file://" + Application.dataPath + "!/assets/buildDB.db");
    }
}
