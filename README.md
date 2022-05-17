# 基于Qt6.3.0开发的教室预约系统

## 软件信息

- Qt6.3.0，x64，社区版

- Mysql8.0，x64，社区版
- DataGrip 2021.3.4，x64
- ODBC，x64

注意：如果Qt的ming_w和Mysql的位数不一样，可能无法连接数据库

## Qt使用说明
组件：比如按钮，文本输入框等等
信号：就是你对组件的操作，比如点击
槽：对组件绑定一个函数，并且找个函数是在private slots:里面声明过的，这样对组件进行操作时候就会触发相应函数执行

## 数据库相关配置

### Mysql配置

把需要的表建出来，建议可以用DataGrip

### ODBC配置

本人使用ODBC连接的mysql，具体操作见下图
![第一步](https://user-images.githubusercontent.com/92586621/168582538-ad091af7-052b-47df-b0fe-ef8715c3b80b.png)
![第二步](https://user-images.githubusercontent.com/92586621/168582544-50a4e958-4043-40d9-b34b-fc90fbc9c581.png)
![第三步](https://user-images.githubusercontent.com/92586621/168582549-71cd62b9-61e7-405a-924c-14d35df90d3f.png)

### 需要的代码

#### pro文件

```c++
QT       += sql  // 必须要有，要不然就没有办法使用操作数据库的相关函数
```

#### .h文件

把相关函数声明出来

#### .cpp文件

函数的实现

#### 注意事项

- 建议把相关变量单独抽出来声明定义，作为配置文件使用

  ```c++
  // .h文件
  #ifndef GLOBE_H
  #define GLOBE_H
  
  #include <QObject>
  #include <QSqlDatabase>
  #include <QSqlQuery>
  #include <QSqlError>
  #include <QPluginLoader>
  #include <QDebug>
  #include <QMessageBox>
  #include <QSqlRecord>
  #include <string>
  using namespace std;
  
  extern QSqlDatabase db;
  extern string hostname;
  extern string databaseName;
  extern string databaseUsername;
  extern string databasePassword;
  extern int port;
  extern QString id;
  
  #endif // GLOBE_H
  
  // .cpp文件
  #include "globe.h"
  
  QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
  string hostname = "localhost";  // ip，写localhost就行
  string databaseName = "system_db";  // 要操作的数据库名称
  string databaseUsername = "";  // 登录mysql账号
  string databasePassword = "";  // 登录mysql密码
  int port = 3306;
  ```

- 建议定义一个数据库工具类

  ```c++
  // .h文件里面声明你要用的操作数据库函数并在.cpp实现，到时候直接加载头文件调用
  // 建议在析构函数中初始化，减少重复代码
  utils_db::utils_db()
  {
      db.setHostName(QString::fromStdString(hostname));
      db.setPort(3306);
      db.setDatabaseName(QString::fromStdString(databaseName));
      db.setUserName(QString::fromStdString(databaseUsername));
      db.setPassword(QString::fromStdString(databasePassword));
      bool connectState = db.open();
      if (connectState){
          qDebug() << "success to connect databse system_db";
      }
      else {
          qDebug() << "fail to connect databse system_db";
      }
  }
  ```

## 如何使用相关函数

```c++
// 查询，此处介绍条件查询使用的prepare函数
QSqlQuery query(db);  // 必须有
query.prepare(sql语句);  // 该方法防止了sql注入，是但是需要调用addBindValue()或者bindValue()对参数参数绑定，具体使用查询代码
query.addBindValue(xx); //绑定参数
query.exec(); //执行
return query.first(); //如果返回query.exec()会出现始终返回true，所以返回query.first()

// 插入，删除，修改
与查询步骤一样，只有sql语句和返回值不一样，可以直接返回insert.exec()，如果是条件查询建议使用prepare函数
```

## 数据库查询可视化

建议使用QSqlTableModel，这个是将数据库查询所有内容按照表格样式输出到Table View这个组件上，使用前必须创建Table View组件

```c++
QSqlTableModel *model = new QSqlTableModel(this, db); // 这个是核心对象
model->setTable(要查的表);
model->setEditStrategy(QSqlTableModel::OnManualSubmit); // 实现修改完之后就可以在数据库更新，不过我没有使用
model->setHeaderData(第几列, Qt::Horizontal, model->tr(列的名称));  // 这个是设置列头的样式，有一个删除列数的方法可以删除你不想要的列，但是我忘记了
ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 这个设置自动调整列宽
ui->tableView->setModel(model);  // 把模型传进tableView
ui->tableView->show();  // 展示

// 一些有用的方法
int row = ui->tableView->currentIndex().row(); // 获取鼠标点击表格位数的行数，可以用来获取该行相关数据，调用getVal方法
model->setFilter(QObject::tr("条件字段 = '%1'").arg(参数));  // 该方法放在ui->tableView->setModel(model)之前用来，筛选查询的数据，'%1'这个是占位符，那个数字可以位任意，多个参数直接在.arg()后面再加.arg()
```

## 提示框

```c++
QMessageBox::information(w ,w->tr(this), w->tr(提示信息)); //这个是提示框

QMessageBox::warning(this, "警告", 警告信息, QMessageBox::Yes);  // 这个是警告框

// 单独抽取出来做成一个工具类可以看我的具体代码
```



**我的所有命名都是见名知意**

上面关于数据库的连接和操作以及把数据库查找出来的数据展示到表格上已经介绍的很详细了，代码里面写的也很清楚，不懂的可以直接找相关代码CV


ps：如果想设计图标可以参考下列代码

```c++
//pro文件
RC_ICONS = logo.ico // 这个logo.ico是你选择的照片的ico格式，可以直接在网上找个转换器转换就可以
```

##### 记录第一次使用Qt开发

##### 如果觉得能帮助到你的话可以给我点个star ~~


