const Sequelize = require("sequelize");

module.exports = class Comment extends Sequelize.Model{
    //테이블 정의
    static init(sequelize)
    {
        return super.init({
            commnet:{
              type: Sequelize.STRING(100),
            allowNull:false         
           }
        }, {
            sequelize,
            timestamps:true, // createAt updateAt 생성
            //underscored:false ,//기본적 테이블명과 컬럼명을 CamelCase로 변경
            modelName:"Commnet",
            tableName:"Commnets",
            paranoid:false, // true로하면 deletedAt 컬럼이 생김
            charset:"utf8mb4",
            collate:"utf8mb4_general_ci"
        })
    }
    //
    static associate(db){
        db.Comment.belongsTo(db.User,{foreignKey:"commenter", targetKey : "id"});
    }
}