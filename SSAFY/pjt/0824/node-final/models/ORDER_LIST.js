const Sequelize = require("sequelize");

module.exports = class OrderList extends Sequelize.Model{
    //테이블 정의
    static init(sequelize)
    {
        return super.init({
        name:{ type: Sequelize.STRING(20),
           },
           type:{
               type:Sequelize.STRING(20)
           }
        }, {
            sequelize,
            timestamps:true, // createAt updateAt 생성
            underscored:false ,//기본적 테이블명과 컬럼명을 CamelCase로 변경
            modelName:"OrderList",
            tableName:"Order_list",
            paranoid:false, // true로하면 deletedAt 컬럼이 생김
            charset:"utf8mb4",
            collate:"utf8mb4_general_ci"
        })
    }
    //
    static associate(db){
    
    }
}