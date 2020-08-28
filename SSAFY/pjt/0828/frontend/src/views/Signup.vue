<template>
  <div>
  <!-- @ => v:on . :value - v-bind -->
    <b-form @submit.prevent="signUp" class="w-50 ml-auto mr-auto mt-5">
      <b-form-group
        id="input-group-1"
        label="아이디(이메일)"
        label-for="input-1"
        description="We'll never share your email with anyone else."
      >   
      <div > {{idMatch}}</div>

        <b-form-input
          id="input-1"
          v-model="form.email"
          type="email"
          required
          placeholder="이메일을 입력하세요"
          @keyup="id_check"
        ></b-form-input>
      </b-form-group>
   

       <b-form-group id="input-group-4" label="이름" label-for="input-4">
        <b-form-input
          id="input-4"
          v-model="form.name"
          required
          placeholder="이름을 입력하세요."
        ></b-form-input>
      </b-form-group>

      <b-form-group id="input-group-2" label="비밀번호" label-for="input-2">
        <b-form-input
          id="input-2"
          v-model="form.password"
          required
          placeholder="비밀번호를 입력하세요."
          type="password"
        ></b-form-input>
      </b-form-group>

       <b-form-group id="input-group-3" label="비밀번호(비밀번호 확인)" label-for="input-3">
          <div > {{pwdMatch}}</div>
        <b-form-input
          id="input-3"
          v-model="form.passwordCheck"
          required
          placeholder="비밀번호 확인을 입력하세요."
          type="password"
          @keyup="pwd_check"
        ></b-form-input>
      </b-form-group>


    <div class="mt-5 d-flex justify-content-center">
      <b-button type="submit" variant="primary">회원가입</b-button>
      <b-button type="reset" variant="danger" class="ml-3">초기화</b-button>
    </div>
    </b-form>
  </div>
</template>

<script>
 import axios from "axios";
 export default {
    data() {
      return {
        form: {
          email: '',
          password:'',
          passwordCheck:'',
          name: ''
        },
        idMatch:"",
        pwdMatch:""
      };
    },
    methods: {
       async signUp(e){
           const {email,password,name} = this.form;
           //console.log(email + " " + password + " " + name);
           if(email && password && name)
           {
               try{
                   const {data} = await axios.post("http://localhost:8000/api/user",{
                       email,password,name
                   })
                   console.log(data);
                   if(data.signup)
                   {
                       alert("회원 가입이 완료 되었습니다.");
                       this.$router.push("/login");
                   }
               }catch(err)
               {
                   console.log(err);
               }
           }
           else{
               alert("아이디 및 비밀번호, 이름을 입력해주세요");
           }
        },
 
 
 async id_check()
    {
        const {email} = this.form;
        console.log(email);
        if(email)
        {
            try{
                    const {data} = await axios.post("http://localhost:8000/api/user/exist",{
                        email
                    });
               if(data.exist)
               {
                  this.idMatch = "사용불가능";
               }
               else{
                   this.idMatch = "사용가능합니다";
               }
            }catch(err)
            {   this.idMatch = "";
                console.log(err);
            }
        }
    },
    async pwd_check()
    {
        if(this.form.password === this.form.passwordCheck)
        {
           this.pwdMatch ="비밀번호가 일치합니다.";
        }
        else{
            this.pwdMatch="비밀번호가 일치하지 않습니다."
        }
    }
    }

  }
</script>