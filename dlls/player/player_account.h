#ifndef PLAYER_ACCOUNT_H
#define PLAYER_ACCOUNT_H
#ifdef _WIN32
#pragma once
#endif

class CBasePlayer;

class CPlayerAccount
{
public:
	CPlayerAccount() : m_iAmount(0), m_iLastAmount(0) {}

	int Get() const
	{
		return m_iAmount;
	}

	CPlayerAccount &operator+=(int delta);

	CPlayerAccount &operator-=(int delta)
	{
		return *this += (-delta);
	}

	CPlayerAccount &operator=(int amount)
	{
		int iDelta = amount - m_iAmount;
		return *this += iDelta;
	}

	operator int() const { return Get(); }

	void UpdateHUD(CBasePlayer *player, bool bTrackChange = false);
	void Reset() { m_iAmount = m_iLastAmount = 0; }

private:
	int m_iAmount;
	int m_iLastAmount;
};

#endif