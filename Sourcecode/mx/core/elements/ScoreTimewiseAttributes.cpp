// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/ScoreTimewiseAttributes.h"
#include "mx/core/FromXElement.h"
#include "mx/xml/XElement.h"
#include "mx/xml/XAttributeIterator.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        ScoreTimewiseAttributes::ScoreTimewiseAttributes()
        :version( "3.0" )
        ,hasVersion( false )
        {}


        bool ScoreTimewiseAttributes::hasValues() const
        {
            return hasVersion;
        }


        std::ostream& ScoreTimewiseAttributes::toStream( std::ostream& os ) const
        {
            if ( hasValues() )
            {
                streamAttribute( os, version, "version", hasVersion );
            }
            return os;
        }


        bool ScoreTimewiseAttributes::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            const char* const className = "ScoreTimewiseAttributes";
            bool isSuccess = true;
        
            auto it = xelement.attributesBegin();
            auto endIter = xelement.attributesEnd();
        
            for( ; it != endIter; ++it )
            {
                if( parseAttribute( message, it, className, isSuccess, version, hasVersion, "version" ) ) { continue; }
            }
        
            MX_RETURN_IS_SUCCESS;
        }

    }
}
