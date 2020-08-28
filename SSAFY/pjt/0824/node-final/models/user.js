const Sequelize = require("sequelize");

module.exports = class User extends Sequelize.Model{
    //테이블 정의
    static init(sequelize)
    {
        return super.init({
            // varchar === string 
            // INT === INTEGER
            // TINYINT  BOOLEAN
            // DATATIME DATE
            // NOT NULL allowNull : false
            // UNIQUE unique:true
            // DEFAULT now() defaultvalue:sequelize.now
            nameL:{ type: Sequelize.STRING(20),
            allowNull:false,
            unique:true                
           },
           age:{
               type:Sequelize.INTEGER.UNSIGNED
           }
        }, {
            sequelize,
            timestamps:true, // createAt updateAt 생성
            underscored:false ,//기본적 테이블명과 컬럼명을 CamelCase로 변경
            modelName:"User",
            tableName:"User",
            paranoid:false, // true로하면 deletedAt 컬럼이 생김
            charset:"utf8mb4",
            collate:"utf8mb4_general_ci"
        })
    }
    //
    static associate(db){
        db.User.hasMany(db.Comment, {foreignKey:"commneter", sourceKey:"id"});
    }
}