#pragma once


class CModelResult
{
public:
	CModelResult(void);
	~CModelResult(void);
	CString m_image_name;
	CString m_image_resolution;
	CString m_result;
	int m_state;
	int m_width;
	int m_height;
};

