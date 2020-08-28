const Sequelize = require("sequelize");


module.exports = class Info extends Sequelize.Model{
    //테이블 정의
    static init(sequelize)
    {
        return super.init({
            name:{ 
                type: Sequelize.STRING(20),
            allowNull:false,
            unique:true
           },
           email:{
            type: Sequelize.STRING(20),
            allowNull:false
           },
           Phone:{
            type: Sequelize.STRING(20),
            allowNull:false
           },
           Adress:{
            type: Sequelize.STRING(30),
            allowNull:true
           },
           Agree:{
            type: Sequelize.BOOLEAN(),
            allowNull:false
           }
        }, {

            sequelize,
            timestamps:false,
            underscored:false ,
            modelName:"Info",
            tableName:"Info",
            paranoid:false, 
            charset:"utf8mb4",
            collate:"utf8mb4_general_ci"
        })
    }
    //
    static associate(db){
      
    }
}