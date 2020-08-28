const Sequelize = require('sequelize');
const User = require("./user");
const Comment =require("./Comment");
const OrderList = require("./ORDER_LIST");
const env = process.env.NODE_ENV || 'development';
const config = require(__dirname + '/../config/config.json')[env];
const db = {};

const sequelize = new Sequelize(
  config.database,
  config.username,
  config.password,
  config
  );
db.sequelize = sequelize;

//User.init(sequelize);
//Comment.init(sequelize);

//User.associate(db);
//Comment.associate(db);

OrderList.init(sequelize);

module.exports = db;
