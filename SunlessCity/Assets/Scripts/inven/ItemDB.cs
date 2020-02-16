using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Data;
using Mono.Data.Sqlite;
public class ItemDB : MonoBehaviour
{
    [SerializeField]
    public List<Items> items = new List<Items>();

    #region 디비
    IDbConnection dbconn;
    IDbCommand dbcmd;
    IDataReader reader;
    #endregion
    void Start()
    {
        string conn = "";

        if (Application.platform == RuntimePlatform.Android)
        {
            conn = "URI=file:" + Application.persistentDataPath + "/buildDB.db";
        }
      else      if(Application.platform == RuntimePlatform.WindowsPlayer)
        {
            conn = "URI=file:" + Application.dataPath + "/buildDB.db";
        }
        else
        {
            conn = "URI=file:" + Application.dataPath + "/buildDB.db";
        }

        dbconn = (IDbConnection)new SqliteConnection(conn);
        dbconn.Open();

        dbcmd = dbconn.CreateCommand();
        string sql = "SELECT * FROM info ORDER BY ID ASC";
        dbcmd.CommandText = sql;
        reader = dbcmd.ExecuteReader();
        while (reader.Read())
        {
            int country = thema_(reader.GetString(3));

            Items it = new Items(reader.GetString(1), reader.GetInt32(5), reader.GetInt32(2), reader.GetInt32(6)
                , reader.GetString(7), reader.GetString(8), country, reader.GetString(9)
                );
            items.Add(it);
        }
        reader.Close();
        reader = null;
        dbcmd.Dispose(); dbcmd = null; dbconn.Close(); dbconn = null;
    }
    int thema_(string s)
    {
        switch (s)
        {
            case "KR":
                return 0;
            case "JP":
                return 1;
            case "NA":
                return 2;
            case "Latin":
                return 3;
            case "EU":
                return 4;
            case "CHN":
                return 5;
            case "SF":
                return 6;
            default:
                return 0;
        }
    }
    void gain()
    {
        int idx = Random.Range(0, 23);
        items[idx].count++;
    }

    void OnApplicationQuit()
    {/*
        string conn = "";

        if (Application.platform == RuntimePlatform.Android)
        {
            conn = "URI=file:" + Application.persistentDataPath + "/buildDb.db";
        }
        else
        {
            conn = "URI=file:" + Application.dataPath + "/buildDB.db";
        }

        dbconn = (IDbConnection)new SqliteConnection(conn);
        dbconn.Open();

        dbcmd = dbconn.CreateCommand();

        for (int i = 0; i < items.Count; i++)
        {
            string sql = string.Format("UPDATE info SET level = {0}, count = {1} where ID = {2}", items[i].level, items[i].count, i + 1);

            dbcmd.CommandText = sql;

            reader = dbcmd.ExecuteReader();

            reader.Close();
            reader = null;
        }
        dbcmd.Dispose(); dbcmd = null; dbconn.Close(); dbconn = null;
        */
    }
}