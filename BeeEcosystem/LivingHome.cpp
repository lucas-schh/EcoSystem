#include "LivingHome.h"

LivingHome::LivingHome(QRectF form, QColor color)
    : mLivingBeings{},
    mForm{ form },
    mColor{color}
{
}

std::vector<LivingBeing*> LivingHome::livingBeing() const
{
    return mLivingBeings;
}


QRectF LivingHome::form() const
{
    return mForm;
}

QColor LivingHome::color() const
{
    return mColor;
}

void LivingHome::die(LivingBeing* livingBeing) {
    auto it(find(mLivingBeings.begin(), mLivingBeings.end(), livingBeing));
    if (it != mLivingBeings.end()) mLivingBeings.erase(it); 
}