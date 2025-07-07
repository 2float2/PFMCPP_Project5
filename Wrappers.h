struct DAWProjectWrapper
{
    DAWProjectWrapper(DAWProject* ptr);
    ~DAWProjectWrapper();
    DAWProject* dawpPtr = nullptr;
};


struct BackstageAreaWrapper
{
    BackstageAreaWrapper(BackstageArea* ptr);
    ~BackstageAreaWrapper();
    BackstageArea* bsaPtr = nullptr;
};


struct LightingRigWrapper
{
    LightingRigWrapper(LightingRig* ptr);
    ~LightingRigWrapper();
    LightingRig* ltrPtr = nullptr;
};


struct AlbumRemakeWrapper
{
    AlbumRemakeWrapper(AlbumRemake* ptr);
    ~AlbumRemakeWrapper();
    AlbumRemake* arPtr = nullptr;
};


struct ConcertHallWrapper
{
    ConcertHallWrapper(ConcertHall* ptr);
    ~ConcertHallWrapper();
    ConcertHall* chPtr = nullptr;
};