const Sequelize = require('sequelize');
const Info = require("./Info");
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


Info.init(sequelize);

module.exports = db;