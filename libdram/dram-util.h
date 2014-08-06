#define min(X, Y)				\
	({ typeof (X) __x = (X);		\
		typeof (Y) __y = (Y);		\
		(__x < __y) ? __x : __y; })

#define max(X, Y)				\
	({ typeof (X) __x = (X); typeof(Y) __y = (Y);	\
		(__x > __y) ? __x : __y; })



/* Absolute value of an integer */
static inline int64_t _abs(int64_t v)
{
    return (v < 0) ? -v : v;
}

/* Sign of an integer */
static inline int64_t _sign(int64_t v)
{
    return v < 0;
}

/* Divide and round results to the nearest integer. */
static inline uint64_t divide_nint(uint64_t dividend, uint64_t divisor)
{
    uint64_t quotent, remainder;
    quotent   = dividend / divisor;
    remainder = dividend % divisor;
    return quotent + ((remainder * 2) >= divisor);
}

/* Divide and round results up to the next higher integer. */
static inline uint64_t divide_roundup(uint64_t dividend, uint64_t divisor)
{
    return (dividend + divisor - 1) / divisor;
}

