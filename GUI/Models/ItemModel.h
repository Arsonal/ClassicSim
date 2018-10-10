#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class Item;
class EquipmentDb;
class ActiveItemStatFilterModel;
class ItemTypeFilterModel;

class ItemSorting : public QObject {
    Q_OBJECT
public:
    enum Methods {
        ByIlvl = 0,
        ByName,
        ByPatch,
        ByItemType
    };
    Q_ENUMS(Methods)
};

class ItemModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ItemRoles {
        NameRole = Qt::UserRole + 1,
        PatchRole,
        SourceRole,
        TypeRole,
        ReqLvlRole,
        ItemLvlRole,
        QualityRole,
        IconRole
    };

    ItemModel(EquipmentDb*, ItemTypeFilterModel*, ActiveItemStatFilterModel*, QObject *parent = nullptr);

    void set_patch(const QString &patch);
    Q_INVOKABLE void setSlot(const int slot);
    Q_INVOKABLE void selectSort(const int method);
    void update_items();

    void addItems(const EquipmentDb *db);
    void addItem(Item* item);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

signals:
    void sortingMethodChanged();

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    int slot;
    EquipmentDb* db;
    ItemTypeFilterModel* item_type_filter_model;
    ActiveItemStatFilterModel* item_stat_filter_model;
    QHash<ItemSorting::Methods, bool> sorting_methods;
    QList<Item*> items;
    ItemSorting::Methods current_sorting_method;

    void select_new_method(const ItemSorting::Methods new_method);
};

#endif // ITEMMODEL_H