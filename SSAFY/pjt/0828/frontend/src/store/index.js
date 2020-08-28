import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    // data 저장할때
    loginData : sessionStorage.getItem("id") ? sessionStorage.getItem("id") : false
  },
  mutations: {
    //state를 변경할때 활용
    SET_LOGIN_DATA(state,data){
      state.loginData = data;
    }
  },
  actions: {
  },
  modules: {
  }
})
