#ifndef B_DELIVERYMANAGER_H
#define B_DELIVERYMANAGER_H

#include "../common/deliverymanager.h"
#include <map>
#include <string>

using namespace std;

namespace Backend {
class DeliveryManager : Common::DeliveryManager {
public:
  DeliveryManager(string deliveryFile);
  ~DeliveryManager();
  map<string, Delivery *> listDelivery() const;
  Delivery *getDeliveryById(string id) const;
  bool addDelivery(Delivery *delivery);
  bool replaceDelivery(Delivery *delivery);

private:
  string deliveryFile;
  map<string, Delivery *> deliveryList;
  void load();
  void save();
  Delivery *copy(Delivery *delivery) const;
  bool addOrReplace(Delivery *delivery);
  Delivery *_getDeliveryById(string id) const;
};
} // namespace Backend

#endif
