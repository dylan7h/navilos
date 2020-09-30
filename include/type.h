#ifndef __TYPE__H__
#define __TYPE__H__

/* IO definitions (access restrictions to peripheral registers) */
#ifdef __cplusplus
  #define   __I     volatile             /*!< \brief Defines 'read only' permissions */
#else
  #define   __I     volatile const       /*!< \brief Defines 'read only' permissions */
#endif
#define     __O     volatile             /*!< \brief Defines 'write only' permissions */
#define     __IO    volatile             /*!< \brief Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*!< \brief Defines 'read only' structure member permissions */
#define     __OM     volatile            /*!< \brief Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*!< \brief Defines 'read / write' structure member permissions */

#ifndef ENABLE
#define ENABLE 1
#endif  //!ENABLE

#ifndef DISABLE
#define DISABLE 0
#endif  //!DISABLE

#ifndef ON
#define ON 1
#endif  //!ON

#ifndef OFF
#define OFF 0
#endif  //!OFF

#ifndef TRUE
#define TRUE 1
#endif  //!TRUE

#ifndef FALSE
#define FALSE 0
#endif  //!FALSE

#endif  //!__TYPE__H__