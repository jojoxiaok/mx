// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/PartNameDisplayAttributes.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        PartNameDisplayAttributes::PartNameDisplayAttributes()
        :printObject( YesNo::no )
        ,hasPrintObject( false )
        {}


        bool PartNameDisplayAttributes::hasValues() const
        {
            return hasPrintObject;
        }


        std::ostream& PartNameDisplayAttributes::toStream( std::ostream& os ) const
        {
            if ( hasValues() )
            {
                streamAttribute( os, printObject, "print-object", hasPrintObject );
            }
            return os;
        }


        bool PartNameDisplayAttributes::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            const char* const className = "PartNameDisplayAttributes";
            bool isSuccess = true;
        
            auto it = xelement.attributesBegin();
            auto endIter = xelement.attributesEnd();
        
            for( ; it != endIter; ++it )
            {
                if( parseAttribute( message, it, className, isSuccess, printObject, hasPrintObject, "print-object", &parseYesNo ) ) { continue; }
            }
        
        
            MX_RETURN_IS_SUCCESS;
        }

    }
}
