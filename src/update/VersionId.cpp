#include "VersionId.h"

VersionId::VersionId(int version, int release, int revision)
    : mVersion(version),
      mRelease(release),
      mRevision(revision)
{}

wxString VersionId::MakeString(int version, int release, int revision)
{
    return std::to_string(version)
        + "." + std::to_string(release)
        + "." + std::to_string(revision);
}

VersionId VersionId::ParseFromString(wxString& versionString)
{
    auto versionStringParts = wxSplit(versionString, '.');

    // If we have corrupted version string,
    // then return the zero version number, that not allow us to update.
    if (versionStringParts.size() != 3)
        return VersionId{};

    for (auto& v : versionStringParts)
    {
        if (v.empty() || !v.IsNumber())
            return VersionId{};
    }

    return VersionId(
        std::stoi(versionStringParts[0].ToStdString()),
        std::stoi(versionStringParts[1].ToStdString()),
        std::stoi(versionStringParts[2].ToStdString())
    );
}

wxString VersionId::getString() const
{
    return MakeString(mVersion, mRelease, mRevision);
}

bool VersionId::operator== (const VersionId& other)
{
    return mVersion == other.mVersion &&
           mRelease == other.mRelease &&
           mRevision == other.mRevision;
}

bool VersionId::operator!= (const VersionId& other)
{
    return !(*this == other);
}

bool VersionId::operator< (const VersionId& other)
{
    if (mVersion < other.mVersion)
        return true;

    if (mRelease < other.mRelease &&
        mVersion == other.mVersion)
        return true;

    if (mRevision < other.mRevision &&
        mVersion == other.mVersion &&
        mRelease == other.mRelease)
        return true;

    return false;
}

bool VersionId::operator> (const VersionId& other)
{
    if (*this == other) return false;

    return !(*this < other);
}