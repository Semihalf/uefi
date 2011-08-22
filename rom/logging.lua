require("utils")

local logging = {}
logging.DEBUG = 3   -- Logs all information including debug
logging.INFO = 2    -- Logs informational, warnings, errors, and fatal
logging.WARN = 1    -- Logs warnings, errors, and fatal. This is the default.

--
-- Internal function that actually writes the message
--
local function log_write(logger, level, arg1, ...)
    printf("%s[%s]: ", level, logger.unit)
    if type(arg1) == "string" then
        printf(arg1, ...)
    else
        pprint(arg1)
    end
end

--
-- Called to log DEBUG messages
--
local function log_debug(logger, arg1, ...)
    if logger.level >= logging.DEBUG then
        log_write(logger, "DEBUG", arg1, ...)
    end
end

--
-- Called to log INFO messages
--
local function log_info(logger, arg1, ...)
    if logger.level >= logging.INFO then
        log_write(logger, "INFO", arg1, ...)
    end
end

--
-- Called to log WARN messages
--
local function log_warn(logger, arg1, ...)
    log_write(logger, "WARN", arg1, ...)
end

--
-- Called to log ERROR messages
--
local function log_error(logger, arg1, ...)
    log_write(logger, "ERROR", arg1, ...)
end

--
-- Called to log FATAL messages
--
local function log_fatal(logger, arg1, ...)
    log_write(logger, "FATAL", arg1, ...)
    error("FATAL message logged")
end

--
-- Create a new logger for a unit. If level isn't specified it defaults
-- to logging.WARN.
--
function logging.new(unit, level)
    local logger = {}
    logger.unit = unit
    logger.level = level or logging.WARN
    logger.debug = log_debug
    logger.info = log_info
    logger.warn = log_warn
    logger.error = log_error
    logger.fatal = log_fatal
    return logger
end

return logging
