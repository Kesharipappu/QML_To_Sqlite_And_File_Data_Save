#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QObject>
#include <QSqlDatabase>

/**

\class DbManager

\brief SQL Database Manager class

DbManager sets up the connection with SQL database

and performs some basics queries. The class requires

existing SQL database. You can create it with sqlite:

$ sqlite3 people.db
sqilte> CREATE TABLE people(ids integer primary key, name text);
sqlite> .quit
*/
class DbManager : public QObject
{
    Q_OBJECT
public:
    explicit DbManager(QObject *parent = nullptr);
    /**

@brief Constructor
Constructor sets up connection with db and opens it
@param path - absolute path to db file
*/
    DbManager(const QString& path);
    /**

@brief Destructor
Close the db connection
*/
    ~DbManager();
    bool isOpen() const;

    /**

@brief Creates a new 'people' table if it doesn't already exist
@return true - 'people' table created successfully, false - table not created
*/
    bool createTable();
    /**

@brief Add person data to db
@param name - name of person to add
@return true - person added successfully, false - person not added
*/
    bool addRecord(const QString &name, const QString &fatherName,
                   const QString &motherName, const QString &mobileNumber,
                   const QString &selectedGender, const QString &qualification,
                   const QString &skills, const QString &state,
                   const QString &city, const QString &landmark,
                   const QString &pincode);

    /**

@brief Remove person data from db
@param name - name of person to remove.
@return true - person removed successfully, false - person not removed
*/
    bool removeRecord(const QString& name);
    /**

@brief Check if person of name "name" exists in db
@param name - name of person to check.
@return true - person exists, false - person does not exist
*/
    bool recordExists(const QString& name) const;
    /**

@brief Print names of all persons in db
*/
    void printAllRecords() const;
    /**

@brief Remove all persons from db
@return true - all persons removed successfully, false - not removed
*/
    bool removeAllRecords();
public slots:

    //It will Save Data From QML UI to Sqlite
    Q_INVOKABLE bool saveToSqlite(const QString &data);
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H

